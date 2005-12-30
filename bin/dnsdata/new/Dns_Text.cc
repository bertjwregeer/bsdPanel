// Standard Library Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Our Mathematics functions
#include "Math.h"

// Required Net Includes
#include "Net_Address.h"
#include "Net_IpAddress.h"
#include "Net_DomainName.h"

// Dns Heirarchy
#include "Dns_Record.h"
#include "Dns_Text.h"

namespace bsdPanel
{
    namespace Dns
    {
        Text::Text() : Record()
        {
            content = new std::string("");
        }
        
        Text::Text(const Text & rhs)
        {
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            content = new std::string(rhs.getContent());
        }
        
        Text::Text(const bsdPanel::Net::DomainName & dname) : Record(dname)
        {
            content = new std::string("");
        }
        
        Text::Text(const bsdPanel::Net::DomainName & dname, const unsigned long ttl)
                    : Record(dname, ttl)
        {
            content = new std::string("");
        }
        
        Text::Text(const bsdPanel::Net::DomainName & dname, const std::string & text)
                    : Record(dname)
        {
            content = new std::string(text);
        }
        
        Text::Text(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                    const std::string & text) : Record(dname, ttl)
        {
            content = new std::string(text);
        }
        
        Text::Text(const std::string & dname) : Record(dname)
        {
            content = new std::string("");
        }
        
        Text::Text(const std::string & dname, const unsigned long ttl) : Record(dname, ttl)
        {
            content = new std::string("");
        }
        
        Text::Text(const std::string & dname, const std::string & text) : Record(dname)
        {
            content = new std::string(text);
        }
        
        Text::Text(const std::string & dname, const unsigned long ttl, const std::string & text)
                    : Record(dname, ttl)
        {
            content = new std::string(text);
        }
        
        Text::~Text()
        {
            delete content;
        }
        
        bool Text::isValid() const
        {
            if (name->isValid())
                return true;
            else
                return false;
        }
        
        Text & Text::operator=(const Text & rhs)
        {
            if (this == &rhs)
                return *this;
            
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            content = new std::string(rhs.getContent());
            
            return *this;
        }
        
        bool Text::operator==(const Text & rhs) const
        {
            if (*name == rhs.getName() &&
                timeToLive == rhs.getTimeToLive() &&
                *content == rhs.getContent())
                return true;
            else
                return false;
        }
        
        std::ostream & Text::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << content;
            return os;
        }
        
        std::string & Text::getContent() const
        {
            return (*content);
        }
    } // end namespace Dns
} // end namespace bsdPanel
