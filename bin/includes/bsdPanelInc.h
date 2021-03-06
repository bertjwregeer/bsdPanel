/**
 * Copyright 2006 Bert JW Regeer. All rights  reserved.
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
 * policies, either expressed  or implied, of bsdPanel project.
 *
**/

#ifndef BSDPANEL_INC
#define BSDPANEL_INC

#ifndef EXIT_FAILURE
#define EXIT_FAILURE -1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0 
#endif

namespace bsdPanel { 
        struct exit_t { 
                explicit exit_t( int n = EXIT_FAILURE ) : code( n ) {} int code; 
        }; 
} 

namespace bsdPanel {
        inline void exit_program(int code = EXIT_FAILURE ) { 
                /*this function never returns*/
                throw bsdPanel::exit_t( code ); 
        }
}

/*
int main() {
        try { // Random stuff here } catch ( bsdPanel::exit_t const& e ) { return e.code; } catch (...) { return EXIT_FAILURE; }
}      
*/

#endif
