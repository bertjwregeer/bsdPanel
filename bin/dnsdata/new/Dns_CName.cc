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
#include "Dns_CName.h"

namespace bsdPanel
{
    namespace Dns
    {
        CName::CName() : Record()
        {
            mapping = new bsdPanel::Net::DomainName();
        }
        
        CName::CName(const CName & rhs)
        {
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            mapping = new rhs.getMapping();
        }
        
        CName::CName(const bsdPanel::Net::DomainName & dname) : Record(dname)
        {
            mapping = new bsdPanel::Net::DomainName();
        }
        
        CName::CName(const bsdPanel::Net::DomainName & dname, const unsigned long ttl)
                : Record(dname, ttl)
        {
            mapping = new bsdPanel::Net::DomainName();
        }

        CName::CName(const bsdPanel::Net::DomainName & dname,
                const bsdPanel::Net::DomainName & map) : Record(dname)
        {
            mapping = new bsdPanel::Net::DomainName(map);
        }
        
        CName::CName(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                const bsdPanel::Net::DomainName & map) : Record(dname, ttl)
        {
            mapping = new bsdPanel::Net::DomainName(map);
        }

        CName::CName(const std::string & dname) : Record(dname)
        {
            mapping = new bsdPanel::Net::DomainName();
        }

        CName::CName(const std::string & dname, const unsigned long ttl) : Record(dname, ttl)
        {
            mapping = new bsdPanel::Net::DomainName();
        }

        CName::CName(const std::string & dname, const std::string & map) : Record(dname)
        {
            mapping = new bsdPanel::Net::DomainName(map);
        }

        CName::CName(const std::string & dname, const unsigned long ttl,
                const std::string & map) : Record(dname, ttl)
        {
            mapping = new bsdPanel::Net::DomainName(map);
        }
        
        CName::~CName()
        {
            delete mapping;
        }
        
        bool CName::isValid() const
        {
            if (name.isValid() && mapping.isValid())
                return true;
            else
                return false;
        }
        
        CName & CName::operator=(const CName & rhs)
        {
            if (this == &rhs)
                return *this;
            
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            mapping = new bsdPanel::Net::DomainName(rhs.getMapping());
            
            return *this;
        }
        
        bool CName::operator==(const CName & rhs) const
        {
            if (name == rhs.getName() &&
                timeToLive == rhs.getTimeToLive &&
                mapping == rhs.getMapping())
                return true;
            else
                return false;
        }
        
        void CName::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << mapping;
        }
        
        bsdPanel::Net::DomainName & CName::getMapping() const
        {
            return mapping;
        }
    } // end namespace Dns
} // end namespace bsdPanel