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
#include "Dns_Host.h"
#include "Dns_Address.h"

namespace bsdPanel
{
    namespace Dns
    {
        Address::Address() : Host()
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const Address & rhs)
        {
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
        }
        
        Address::Address(const bsdPanel::Net::DomainName & dname) : Host(dname)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const bsdPanel::Net::DomainName & dname, 
                            const unsigned long ttl) : Host(dname, ttl)
        {
            // empty constructor, uses parent
        }
                
        Address::Address(const bsdPanel::Net::DomainName & dname, 
                            const bsdPanel::Net::IpAddress & ip_addr) : Host(dname, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const bsdPanel::Net::DomainName & dname, const std::string & ip_addr) : Host(dname, ip_addr)
        {
            // empty constructor, uses parent
        }
                
        Address::Address(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr) : Host(dname, ttl, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const std::string & ip_addr) : Host(dname, ttl, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const std::string & dname) : Host(dname)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const std::string & dname, const unsigned long ttl) : Host(dname, ttl)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr) : Host(dname, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const std::string & dname, const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr) : Host(dname, ttl, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const std::string & dname, 
                            const std::string & ip_addr) : Host(dname, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Address::Address(const std::string & dname, const unsigned long ttl,
                            const std::string & ip_addr) : Host(dname, ttl, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Address::~Address()
        {
            // empty destructor, uses parent
        }
        
        bool Address::isValid() const
        {
            if (name->isValid() && ipAddress->isValid())
                return true;
            else
                return false;
        }
        
        Address & Address::operator=(const Address & rhs)
        {
            if (this == &rhs)
                return *this;
            
            if (name != NULL) delete name;
            if (ipAddress != NULL) delete ipAddress;
            
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
            
            return *this;
        }
        
        bool Address::operator==(const Address & rhs) const
        {
            if (this == &rhs)
                return true;
            
            if (*name == rhs.getName() &&
                timeToLive == rhs.getTimeToLive() &&
                *ipAddress == rhs.getAddress())
                return true;
            else
                return false;
        }
        
        std::ostream & Address::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << ipAddress;
            return os;
        }
    } // end namespace bsdPanel
} // end namespace bsdPanel
