/*
 * Copyright 2005 X-Istence.com. All rights  reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and  documentation are
 * those of the authors and should not be  interpreted as representing official
 * policies, either expressed  or implied, of X-Istence.com or the bsdPanel
 * project.
 *
 * $Id$
 */

#ifndef BSDPANEL_PIPESTREAM
#define BSDPANEL_PIPESTREAM

#include <istream>
#include <ostream>
#include <streambuf>
#include <iostream>
#include <cstudio>
#include <cstring>

#include <unistd.h>

namespace bsdPanel {
        
        /*
         * pipeoutbuf is a class which extends streambuf and defines the virtual 
         * function named overflow and xsputn which allow us to send the data
         * over a pipe named "fd" using write.
         *
         * Eventhough I wrote bits and pieces of this. Most of the credit should go
         * to the many programmers who wrote the code before me, from whose examples
         * I learned. Most notably from comp.lang.c++. 
         */
        
        class pipeoutbuf : public std::streambuf {
                // Declaration of variable before it is used
                protected:
                        int fd;
                public:
                        pipeoutbuf () : fd(-1) {}
                        pipeoutbuf (int myfd) : fd(myfd) {}
                        
                        void attach (int _fd) {
                                flush();
                                fd = _fd;
                        }
                        
                protected:
                        // Write one character
                        virtual int_type overflow (int_type g) {
                                if (g != EOF) {
                                        char z = g;
                                        if (write (fd, &z, 1) != 1) {
                                                return EOF;
                                        }
                                }
                        return c;
                        }
                        
                        virtual std::streamsize xsputn (const char* s, std::streamsize num) {
                                return write(fd, s, num);
                        }
        };
        
        /*
         * opipestream, just a basic wrapper which extends std::ostream. When you call 
         * it, you pass it an "fd" which is an open file descriptor, and from then on
         * you can use it like you would use cout. bsdPanel::opipestream blah(write[0]);
         * blah << someString;
         */
        
        class opipestream : public std::ostream {
                protected:
                        pipeoutbuf buf;
                public:
                        opipestream (int fd) : std::ostream(0), buf(fd) {
                                rdbuf(&buf);
                        }
        };
        
        /*
         * pipeinbuf is a class which extends std::streambuf. It is used for buffering
         * when reading from pipes. It reads from a standard file descriptor.
         *
         * Eventhough I wrote bits and pieces of this. Most of the credit should go
         * to the many programmers who wrote the code before me, from whose examples
         * I learned. Most notably from comp.lang.c++. 
         *
         * Did I note that messing with character arrays is a pain in the ass?
         */
        
        class pipeinbuf : public std::streambuf {
                protected:
                        int fd;
                        
                        /* data buffer:
                         * - at most, pbSize characters in putback area plus
                         * - at most, bufSize characters in ordinary read buffer
                         */
                         
                         static const int pbSize = 8;        // size of putback area
                         static const int bufSize = 1024;    // size of the data buffer
                         char buffer[bufSize+pbSize];        // data buffer
                public:
                        /* constructor
                         * - initialize file descriptor
                         * - initialize empty data buffer
                         * - no putback area
                         * => force underflow()
                         */
                         
                         pipeinbuf () : fd(-1) {
                                setg (buffer+pbSize,     // beginning of putback area
                                        buffer+pbSize,     // read position
                                        buffer+pbSize);    // end position
                        }
                         
                         pipeinbuf (int myfd) : fd(myfd) {
                                setg (buffer+pbSize,     // beginning of putback area
                                        buffer+pbSize,     // read position
                                        buffer+pbSize);    // end position
                        }
                        
                        void attach(int _fd) {
                                setg (buffer+pbSize,     // beginning of putback area
                                        buffer+pbSize,     // read position
                                        buffer+pbSize);    // end position
                                fd = _fd;
                        }
                        
                protected:
                        // insert new characters into the buffer
                        virtual int_type underflow () {
                                // is read position before end of buffer?
                                if (gptr() < egptr()) {
                                        return traits_type::to_int_type(*gptr());
                                }
                                
                                /* process size of putback area
                                 * - use number of characters read
                                 * - but at most size of putback area
                                 */
                                 
                                int numPutback;
                                numPutback = gptr() - eback();
                                if (numPutback > pbSize) {
                                       numPutback = pbSize;
                                }
        
                                /* copy up to pbSize characters previously read into
                                 * the putback area.
                                 * memmove is used becauce some example on google's newsgroup told me to use it.
                                 */
                                
                                memmove (buffer+(pbSize-numPutback), gptr()-numPutback, numPutback);

                                // read at most bufSize new characters
                                int num;
                                num = read (fd, buffer+pbSize, bufSize);
                                if (num <= 0) {
                                        // ERROR or EOF
                                        return EOF;
                                }
                                
                                // reset buffer pointers
                                setg (buffer+(pbSize-numPutback),   // beginning of putback area
                                        buffer+pbSize,                // read position
                                        buffer+pbSize+num);           // end of buffer
                                
                                // return next character
                                return traits_type::to_int_type(*gptr());
                        }
        };

        /*
         * opipestream, just a basic wrapper which extends std::istream. When you call 
         * it, you pass it an "fd" which is an open file descriptor, and from then on
         * you can use it like you would use cin. bsdPanel::ipipestream blah(read[1]);
         * ipipestream >> someString;
         */
         
        class ipipestream : public std::istream {
                protected:
                        fdinbuf buf;
                public:                        
                        ipipestream (int fd) : std::istream(0), buf(fd) {
                                rdbuf(&buf);
                        }
        };        
}

#endif
