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

#ifndef BSDPANEL_CONFIG_H
#define BSDPANEL_CONFIG_H
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

// TODO: Check if there are no memory leaks that can occur, preferably using a tool like Valgrind.

namespace bsdPanel {
        class Config {
        public:
                class ConfigCont
                {
                public:
                        ConfigCont ();
                        virtual ~ConfigCont () = 0;
                        virtual bool add (std::string const & name, std::string const & param, std::string const & value) = 0;
                        virtual bool done () = 0;
                };
                
                Config (std::string const & path, Config::ConfigCont * cont);
                const bsdPanel::Config::ConfigCont* getConfig();
                bool runParse();

        private:
                inline bool _addContainer(std::string const & name, std::string const & param, std::string const & value);
                inline const char _checkCharacter(char const & c);
                enum State { Searching, Program, ClosingBrace, Parameter, Value };
                
                State _state;
                std::ifstream _input;
                Config::ConfigCont * _cont;
                bool _parseDone;
                unsigned int _line;
                
                Config () {}
                Config (Config&);
                Config& operator = (Config&);
        };
        
        namespace ConfigExcept {
                class NoExist : public std::runtime_error {
                        public:
                                NoExist() 
                                        : std::runtime_error("Config file does not exist") { };
                };
                
                class WrongMode : public std::runtime_error {
                        public:
                                WrongMode()
                                        : std::runtime_error("Config file is not chmod 400") { };
                };
                
                class OpenFailure : public std::runtime_error {
                        public:
                                OpenFailure()
                                        : std::runtime_error("Failure to open config file") {};
                };
                
                class SyntaxError : public std::exception {
                        std::string _msg;
                        
                        public:
                                SyntaxError(const int line, const std::string&  _arg) {
                                        std::stringstream iss;
                                        iss << line;
                                        _msg = "Syntax Error (" + iss.str() + "): " + _arg;
                                }
                                
                                ~SyntaxError() throw() {};
                                
                                const char* what() const throw() {
                                        return _msg.c_str();
                                }
                };
                
        }

}

#endif
