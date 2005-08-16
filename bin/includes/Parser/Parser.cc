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
 */
 
#include <Parser/Parser.h>
 
bsdPanel::Parser::~Parser() {
        std::vector<bsdPanel::Parser::p_type *>::iterator a = matcher->begin();
        while (a != matcher->end() ) {
                delete (*a);
                a = matcher->erase(a);
        }
}

void bsdPanel::Parser::parseMatch(std::string const & _match, std::string const & _cmts) {
        parseMatch__(_match, _cmts);
}

void bsdPanel::Parser::parseMatch(std::string const & _match) {
        parseMatch__(_match, std::string("#/"));
}

void bsdPanel::Parser::prepareMatch__() {
        matcher = new std::vector<bsdPanel::Parser::p_type *>();
        
        bsdPanel::Parser::p_type * type_temp = 0 ;
        int limit = 0;
        int domatch = 0;
        
        for ( std::string::iterator a = match->begin(), b = match->end(); a!=b; ++a ) {
                if (type_temp != 0)
                        throw bsdPanel::TypeTempMatch(); // this should never happen. It is like a security feature.
                                                         // If you find you are catching this, this code needs a rewrite :P
                
                if ( (*a) == '(') {
                        domatch = 1;
                        continue;
                }
                
                if ( (*a) == ')') {
                        domatch = 0;
                        continue;
                }
                
                // Checking the special case characters.
                if ( (*a) == '\\' ) {
                        switch ( (*(++a)) ) {
                                case '\\':
                                        type_temp = new p_type();
                                        *(type_temp->type) = 4;
                                        (type_temp->text)->append("\\");
                                        break;
                                case 't':
                                        type_temp = new p_type();
                                        
                                        if (domatch == 0)
                                                *(type_temp->type) = 2;
                                        else if (domatch == 1)
                                                *(type_temp->type) = 3;
                                        limit = 1;
                                        break;
                                case 'w':
                                        type_temp = new p_type();
                                        *(type_temp->type) = 1;
                                        limit = 1;
                                        break;
                                case '[':
                                        type_temp = new p_type();
                                        *(type_temp->type) = 4;
                                        (type_temp->text)->append("[");
                                        break;
                                case ']':
                                        type_temp = new p_type();
                                        *(type_temp->type) = 4;
                                        (type_temp->text)->append("]");
                                        break;
                                case '(':
                                        type_temp = new p_type();
                                        *(type_temp->type) = 4;
                                        (type_temp->text)->append("(");
                                        break;
                                case ')':
                                        type_temp = new p_type();
                                        *(type_temp->type) = 4;
                                        (type_temp->text)->append(")");
                                        break;
                                default:
                                        break;
                        }
                }
                
                // Set limits if needed. Only special cases get limits. Like \t and \w.
                if ( limit && (*(++a)) == '[' ) {
                        // We are going to set min/max length.
                        // [2,5] = minlength: 2; maxlength: 5
                        // [5] = minlength: 5; maxlength: 5
                        // [2,] minlength: 2; maxlength: -1 (unlimited)
                        // [,10] minlength: 0; maxlength: 10
                        
                        ++a;
                        
                        std::stringstream * mystream = new std::stringstream();
                        
                        // Test to check if we are going to only set maxlength
                        if ( (*a) == ',' ) {
                                while ( (*(++a)) != ']')
                                        *mystream << (*a);
                                
                                *mystream >> *(type_temp->maxlength);
                        }
                        
                        if ( num.find((*a)) != std::string::npos ) {
                                *mystream << (*a);
                                while ( (*(++a)) != ']' && (*a) != ',')
                                        *mystream << (*a);
                                
                                *mystream >> *(type_temp->minlength);
                                
                                
                                if ( (*a) != ']' && ( (*a) == ',' && (*(++a)) != ']' ) ) {
                                        mystream->ignore(std::numeric_limits<int>::max());
                                        --a;
                                        while ( (*(++a)) != ']' )
                                                *mystream << (*a);
                                        
                                        *mystream >> *(type_temp->maxlength);
                                }
                                
                                else if ( (*a) == ']') {
                                        *(type_temp->maxlength) = -1;
                                }
                        }
                }
                else if (limit) {
                        --a;
                }
                
                // Normal characters which get stored in strings
                if ( !limit && !domatch && (type_temp == 0 || *(type_temp->type) == 4) ) {
                        if (type_temp == 0) {
                                type_temp = new p_type();
                                *(type_temp->type) = 4;
                        }
                                
                        
                        (type_temp->text)->append(getString__(a, b));
                        
                } 
        }               
}
void bsdPanel::Parser::parseMatch__(std::string const & _match, std::string const & _cmts) {
        match = new std::string(_match);
        cmts = new std::string(_cmts);
        
        if (match->length() <= 0)
                throw NoMatch();
        
        int anh = 0;
        int pnh = 0;
        int spc = 0;
        for ( std::string::iterator a = match->begin(), b = match->end(); a!=b; ++a ) {
                if ( spc == 0 && (*a) == '(' ) {
                        if ( anh != 0 )
                                throw NestedMatch();
                        anh++;
                }
                if ( spc == 0 && (*a) == ')' )
                        anh--;
                        
                if ( spc == 0 && (*a) == '[' ) {
                        if ( pnh != 0 )
                                throw NestedMatch();
                        pnh++;
                }
                
                if ( spc == 0 && (*a) == ']' )
                        pnh--;
                
                if ( spc == 0 && (*a) == '\\' ) {
                        if (spc == 1)
                                spc = 0;
                        else
                                spc = 1;
                }
                
                if ( spc == 1 ) {
                        switch ( (*a) ) {
                            case 't':
                            // case 's':
                            case 'w':
                            case '[':
                            case ']':
                            case '\\':
                            case '(':
                            case ')':
                                    spc = 0;
                                    break;
                            default:
                                    throw FaultMatch();
                        }
                }
        }
        
        if (anh != 0)
                throw FaultMatch();
                
        if (pnh != 0)
                throw FaultMatch();
        
        if (spc != 0)
                throw FaultMatch(); 
}

bsdPanel::Parser::p_type::p_type() {
        type = new int();
        minlength = new int();
        maxlength = new int();
        text = new std::string();
}

bsdPanel::Parser::p_type::~p_type() {
        delete type;
        delete minlength;
        delete maxlength;
        delete text;
}
