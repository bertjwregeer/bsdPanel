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

#ifndef BSDPANEL_PARSER
#define BSDPANEL_PARSER
 
#include <string>
#include <sstream>
#include <vector>

#include <Parser/ParsedContainer.h>
#include <Exceptions/Exceptions.h>
#include <bsdPanelInc.h>

namespace bsdPanel {
        class Parser {
                public:
                        Parser() : whitespace("\t\r\n "),
                                   alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"),
                                   num("1234567890"),
                                   alphanum(alpha + num),
                                   rchars("{}!@#$%^&*~,./?+-|;:"),
                                   all(alphanum + rchars) {};
                        ~Parser();
                        void parseText(std::string const & _parse, bsdPParser::ParsedContainer const & _pcont);
                        void parseMatch(std::string const & _match, std::string const & _cmts);
                        void parseMatch(std::string const & _match);
                        
                private:
                
                        class p_type {
                                public:
                                        p_type();
                                        ~p_type();
                                                // These are the types we have:
                                                // 1. Whitespace
                                                // 2. Any random characters
                                                // 3. Match it. This we are going to place in the ParsedContainer.
                                                // 4. Straight forward text which is kept in the variable text
                                        int * type;
                                        int * minlength;
                                        int * maxlength;
                                        std::string * text;
                        };
                        
                        std::string * match;
                        std::string * cmts;
                        std::vector<bsdPanel::Parser::p_type *> * matcher;
                        const std::string whitespace;
                        const std::string alpha;
                        const std::string num;
                        const std::string alphanum;
                        const std::string rchars;
                        const std::string all;
                        
                        // Internal function for parseMatch.
                        void parseMatch__ (std::string const & _match, std::string const & _cmts);
                        // Internal function to prepare for matching.
                        void prepareMatch__ ();
                        std::string getString__ (std::string::iterator & _start, std::string::iterator & _end)
        };
}

#endif