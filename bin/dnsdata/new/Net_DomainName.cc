#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Math.h"
#include "Net_Address.h"
#include "Net_DomainName.h"
#include "Net_DomainNameException.h"

namespace bsdPanel
{
    namespace Net
    {
        DomainName::DomainName() : Address()
        {
            name = new std::string("example.net");
            
            if ( !isValid() )
                throw DomainNameException(DomainNameException::INVALID_ADDRESS);
        }
        
        DomainName::DomainName(const DomainName & rhs) : Address(rhs.getDelim())
        {
            delim = rhs.getDelim();
            name = new std::string(rhs.getName());
            
            if ( !isValid() )
                throw DomainNameException(DomainNameException::INVALID_ADDRESS);
        }
        
        DomainName::DomainName(const std::string & dname) : Address()
        {
            name = new std::string(dname);
        }
        
        DomainName::~DomainName()
        {
            delete name;
        }
        
        bool DomainName::isValid() const
        {
            bool check = false;
            std::vector<std::string>::iterator code =
                find (domain_code->begin(), domain_code->end(), suffix());
            
            if ( code != domain_code->end() )
                check = true;
            
            return check;
        }
        
        DomainName & DomainName::operator=(const DomainName & rhs)
        {
            if (this == &rhs)
                return *this;
            
            delim = rhs.delim;
            
            if (name != NULL) {
                delete name;
            }
            
            name = new std::string(rhs.getName());
            return *this;
        }
        
        bool DomainName::operator==(const DomainName & rhs) 
        {
            if ((this == &rhs) ||
                (delim == rhs.delim && name == rhs.name))
                return true;
            else
                return false;
        }
        
        std::ostream & DomainName::output(std::ostream & os) const
        {
            os << name;
            return os;
        }
        
        std::string & DomainName::getName() const
        {
            return *name;
        }
        
        std::string DomainName::suffix() const
        {
            int pos = name->rfind(delim, name->length());
            return (name->substr(pos, name->length()));
        }
        
        void DomainName::load_domain_codes()
        {
            domain_code = new std::vector<std::string>;
            
            // Ok, we need to open the file with the codes and
            // store them into the domainCode vector
            std::ifstream codes;
            codes.open("Net_DomainNameCodes.dat");
            
            std::string code;
            
            if (codes.is_open()) {
                // file is open, we can now read the contents into the vector
                do { 
                    std::getline(codes, code);
                    domain_code->push_back(code);
                } while (!codes.eof());

            } else {
                // Error reading file, we need to decide how to deal with this
                // Throw an exception :P
                throw DomainNameException(DomainNameException::LOAD_DOMAIN_CODE_ERROR);
            }
            
            codes.close();
        }
    }
}
