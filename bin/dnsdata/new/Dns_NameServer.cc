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
#include "Dns_NameServer.h"

namespace bsdPanel
{
    namespace Dns
    {
        NameServer::NameServer() : Record()
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns.example.com");
        }
        
        NameServer::NameServer(const NameServer & rhs) 
        {
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
            nameserver = new bsdPanel::Net::DomainName(rhs.getNSName());
        }
        
        // bsdPanel::Net::DomainName constructors
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.asString());
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.asString());
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const bsdPanel::Net::IpAddress & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.asString());
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const std::string & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.asString());
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.asString());
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const std::string & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.asString());
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const std::string & ip_addr, const bsdPanel::Net::DomainName & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const std::string & ip_addr, const std::string & ns) : Record(dname) 
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const std::string & ip_addr, const bsdPanel::Net::DomainName & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const std::string & ip_addr, const std::string & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        // String dname constructors
        NameServer::NameServer(const std::string & dname) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
                
        NameServer::NameServer(const std::string & dname, const unsigned long ttl) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer::NameServer(const std::string & dname, const std::string & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer::NameServer(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer::NameServer(const std::string & dname, const unsigned long ttl, const std::string & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer::NameServer(const std::string & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer::NameServer(const std::string & dname, const std::string & ip_addr, const std::string & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const std::string & dname, const std::string & ip_addr, const bsdPanel::Net::DomainName & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const std::string & dname, const unsigned long ttl, const std::string & ip_addr, const std::string & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const std::string & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const std::string & dname, const unsigned long ttl, const std::string & ip_addr, const bsdPanel::Net::DomainName & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::NameServer(const std::string & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer::~NameServer()
        {
            delete ipAddress;
            delete nameserver;
        }
        
        bool NameServer::isValid() const
        {
            if (name->isValid() &&
                ipAddress->isValid() &&
                nameserver->isValid())
                return true;
            else
                return false;
        }
        
        NameServer & NameServer::operator=(const NameServer & rhs)
        {
            if (this == &rhs)
                return *this;
            
            // need to check for existing values and cleanup before assignment
            if (name != NULL) delete name;
            if (ipAddress != NULL) delete ipAddress;
            if (nameserver != NULL) delete nameserver;
            
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
            nameserver = new bsdPanel::Net::DomainName(rhs.getNSName());
            
            return *this;
        }
        
        bool NameServer::operator==(const NameServer & rhs) const
        {
            if (*name == rhs.getName() &&
                timeToLive == rhs.getTimeToLive() &&
                *ipAddress == rhs.getAddress() &&
                *nameserver == rhs.getNSName())
                return true;
            else
                return false;
        }
        
        std::ostream & NameServer::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << ipAddress << ":" << nameserver;
            return os;
        }
        
        bsdPanel::Net::IpAddress & NameServer::getAddress() const
        {
            return (*ipAddress);
        }
        
        bsdPanel::Net::DomainName & NameServer::getNSName() const
        {
            return (*nameserver);
        }
    } // end namespace Dns
} // end namespace bsdPanel
