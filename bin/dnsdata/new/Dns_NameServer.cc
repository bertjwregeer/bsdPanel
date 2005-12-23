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
        
        NameServer(const bsdPanel::Net::DomainName & dname) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.getAddress().asString());
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl)
                    : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.getAddress().asString());
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.getAddress().asString());
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname.getAddress().asString());
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns) 
                    : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns)
                    : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const std::string & dname) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer(const std::string & dname, const unsigned long ttl) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer(const std::string & dname, const std::string & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer(const std::string & dname, const unsigned long ttl, const std::string & ip_addr)
                    : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName("a.ns." + dname);
        }
        
        NameServer(const std::string & dname, const std::string & ip_addr, const std::string & ns)
                    : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        } // dname, ip_addr, nameserver
        
        NameServer(const std::string & dname, const unsigned long ttl, const std::string & ip_addr,
                    const std::string & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        // Constructors that cover the mixed parameters
        NameServer(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const std::string & dname, const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns) 
                    : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        
        NameServer(const std::string & dname, const std::string & ip_addr, 
                    const bsdPanel::Net::DomainName & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const std::string & dname, const unsigned long ttl, 
                    const std::string & ip_addr, const bsdPanel::Net::DomainName & ns)
                    : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        
        NameServer(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const std::string & dname, const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns)
                    : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname, const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, 
                    const std::string & ip_addr, const bsdPanel::Net::DomainName & ns)
                    : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        
        NameServer(const bsdPanel::Net::DomainName & dname, const std::string & ip_addr,
                    const std::string & ns) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                    const std::string & ip_addr, const std::string & ns) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        
        NameServer(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns)
                    : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
            nameserver = new bsdPanel::Net::DomainName(ns);
        }
        
        NameServer(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns)
                    : Record(dname, ttl)
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
            if (name.isValid() &&
                ipAddress.isValid() &&
                nameserver.isValid())
                return true;
            else
                return false;
        }
        
        NameServer & NameServer::operator=(const NameServer & rhs)
        {
            if (this == &rhs)
                return *this;
            
            name = rhs.getName();
            timeToLive = rhs.getTimeToLive();
            ipAddress = rhs.getAddress();
            nameserver = rhs.getNSName();
            
            return *this;
        }
        
        bool NameServer::operator==(const NameServer & rhs) const
        {
            if (name == rhs.getName() &&
                timeToLive == rhs.getTimeToLive() &&
                ipAddress == rhs.getAddress() &&
                nameserver == rhs.getNSName())
                return true;
            else
                return false;
        }
        
        void NameServer::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << ipAddress << ":" << nameserver;
        }
        
        bsdPanel::Net::IpAddress & NameServer::getAddress() const
        {
            return ipAddress;
        }
        
        bsdPanel::Net::DomainName & NameServer::getNSName() const
        {
            return nameserver;
        }
    } // end namespace Dns
} // end namespace bsdPanel