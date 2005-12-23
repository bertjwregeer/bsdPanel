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
#include "Dns_Alias.h"

namespace bsdPanel
{
    namespace Dns
    {
        Alias::Alias() : Host()
        {
            // empty constructor, uses parent
        }
        
        Alias::Alias(const Alias & rhs)
        {
            name = new bsdPanel::Net::DomainName(rhs.getName());
            ttl = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
        }
        
        Alias::Alias(const bsdPanel::Net::DomainName & dname) : Host(dname)
        {
            // empty constructor, uses parent
        }
        
        Alias::Alias(const bsdPanel::Net::DomainName & dname, 
                            const unsigned long ttl) : Host(dname, ttl)
        {
            // empty constructor, uses parent
        }
                
        Alias::Alias(const bsdPanel::Net::DomainName & dname, 
                            const bsdPanel::Net::IpAddress & ip_addr) : Host(dname, ip_addr)
        {
            // empty constructor, uses parent
        }
                
        Alias::Alias(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr) : Host(dname, ttl, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Alias::Alias(const std::string & dname) : Host(dname)
        {
            // empty constructor, uses parent
        }
        
        Alias::Alias(const std::string & dname, const unsigned long ttl) : Host(dname, ttl)
        {
            // empty constructor, uses parent
        }
        
        Alias::Alias(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr) : Host(dname, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Alias::Alias(const std::string & dname, const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr) : Host(dname, ttl, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Alias::Alias(const std::string & dname, 
                            const std::string & ip_addr) : Host(dname, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Alias::Alias(const std::string & dname, const unsigned long ttl,
                            const std::string & ip_addr) : Host(dname, ttl, ip_addr)
        {
            // empty constructor, uses parent
        }
        
        Alias::~Alias()
        {
            // empty destructor, uses parent
        }
        
        bool Alias::isValid() const
        {
            if (name.isValid() && ipAddress.isValid())
                return true;
            else
                return false;
        }
        
        Alias & Alias::operator=(const Alias & rhs)
        {
            if (this == &rhs)
                return *this;
            
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
            
            return *this;
        }
        
        bool Alias::operator==(const Alias & rhs) const
        {
            if (this == &rhs)
                return true;
            
            if (name == rhs.getName() &&
                timeToLive == rhs.getTimeToLive() &&
                ipAddress == rhs.getAddress())
                return true;
            else
                return false;
        }
        
        void Alias::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << ipAddress;
        }
    } // end namespace bsdPanel
} // end namespace bsdPanel