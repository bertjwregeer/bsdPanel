/**
 * Copyright 2006 Bert JW Regeer. All rights  reserved.
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
 * policies, either expressed  or implied, of bsdPanel project.
 *
**/
 
#include "Config.h"

bsdPanel::Config::Config(std::string const & path, Config::ConfigCont * cont)  : _cont(cont), _parseDone(false), _line(0) {
        struct stat st;
        if (stat(path.c_str(), &st) == -1)        throw bsdPanel::ConfigExcept::NoExist();
        if ( (st.st_mode & (S_IRWXG | S_IRWXO)) ) throw bsdPanel::ConfigExcept::WrongMode();
        if ( (st.st_mode & ALLPERMS) == 000)      throw bsdPanel::ConfigExcept::WrongMode();

        _input.open(path.c_str(), std::ios::in);

        if (!_input.is_open()) throw bsdPanel::ConfigExcept::OpenFailure();
}

bool bsdPanel::Config::runParse() {
        if (_parseDone) return true;
        
        std::string cline, prgrm, param, value;
        _state = Searching;
        while(getline(_input, cline)) {
                _line++;
                for (std::string::const_iterator a = cline.begin(), b = cline.end(); a!=b; a++) {
                        if ( (*a) == '#') break;
                        if ( ((*a) == ' ' || (*a) == '\t') && !((_state == Value) && !value.empty()) ) continue;
                        
                        switch (_state) {
                                case Searching:
                                        prgrm += _checkCharacter(*a);
                                        _state = Program;
                                        break;
                                case Program:
                                        if ( (*a) != '{') {
                                                prgrm += _checkCharacter(*a);
                                        }
                                        else {
                                                _state = ClosingBrace;
                                        }
                                        break;
                                case ClosingBrace:
                                        if ( (*a) != '}') {
                                                param += _checkCharacter(*a);
                                                _state = Parameter;
                                        }
                                        else {
                                                prgrm = param = value = "";
                                                _state = Searching;
                                        }
                                        break;
                                case Parameter:
                                        if ( (*a) != ':') {
                                                param += _checkCharacter(*a);
                                        }
                                        else {
                                                _state = Value;
                                        }
                                        break;
                                case Value:
                                        if ( (*a) != ';') {
                                                if ( (*a) == '\\') {
                                                        if (++a == b)  // Add 1 to a, check if it is the end (b)
                                                                --a;   // Don't screw up the for loop, reduce a
                                                        else
                                                                value += (*(++a)); // Add the character without any character checking
                                                }
                                                else {
                                                        value += _checkCharacter(*a);
                                                }
                                        }
                                        else {
                                                _addContainer(prgrm, param, value);
                                                param = value = "";
                                                _state = ClosingBrace;
                                        }
                                        break;
                                default:
                                        return false;
                                        break;
                        }
                }
        }
        
        if (!(_state == Searching)) {
                throw bsdPanel::ConfigExcept::SyntaxError(_line, "EOF reached, missing }");
        }
        return _cont->done();
}

inline const char bsdPanel::Config::_checkCharacter(char const & c) {
        if ('}' == c && !(_state == ClosingBrace)) {
                throw bsdPanel::ConfigExcept::SyntaxError(_line, "Unexpected }");
        }
        if (';' == c && !(_state == Value)){
                throw bsdPanel::ConfigExcept::SyntaxError(_line, "Unexpected ;");
        }
        if (':' == c && !(_state == Parameter)) {
                throw bsdPanel::ConfigExcept::SyntaxError(_line, "Unexpected :");
        }
        if ('{' == c && !(_state == Program)) {
                throw bsdPanel::ConfigExcept::SyntaxError(_line, "Unexpected {");
        }
        
        return c;
}

inline bool bsdPanel::Config::_addContainer(std::string const & name, std::string const & param, std::string const & value) {
        if (name.empty() || param.empty() || value.empty()) {
                throw bsdPanel::ConfigExcept::SyntaxError(_line, "Config: Absolute failure!");
        }
        
        return _cont->add(name, param, value);
}

const bsdPanel::Config::ConfigCont* bsdPanel::Config::getConfig() {
        return this->_cont;
}

bsdPanel::Config::ConfigCont::ConfigCont() { }

bsdPanel::Config::ConfigCont::~ConfigCont() { }