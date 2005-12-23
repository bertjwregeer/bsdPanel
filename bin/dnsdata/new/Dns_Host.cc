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

namespace bsdPanel
{
    namespace Dns
    {
        Host::Host() : Record()
        {
            ipAddress = new bsdPanel::Net::IpAddress();
        }
        
        Host::Host(const bsdPanel::Net::DomainName & dname) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
        }
        
        Host::Host(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
        }
        
        Host::Host(const bsdPanel::Net::DomainName & dname, 
                    const bsdPanel::Net::IpAddress & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
        }
        
        Host::Host(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
        }
        
        Host::Host(const std::string & dname) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
        }
        
        Host::Host(const std::string & dname, const unsigned long ttl) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress();
        }
        
        Host::Host(const std::string & dname, 
                    const bsdPanel::Net::IpAddress & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
        }
        
        Host::Host(const std::string & dname, const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
        }
        
        Host::Host(const std::string & dname, const std::string & ip_addr) : Record(dname)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
        }
        
        Host::Host(const std::string & dname, const unsigned long ttl, 
                    const std::string & ip_addr) : Record(dname, ttl)
        {
            ipAddress = new bsdPanel::Net::IpAddress(ip_addr);
        }
        
        Host::~Host()
        {
            delete ipAddress;
        }
        
        // look into possibility of calling parent output function in this and
        // then appending this classes data to that output.
        void Host::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << ipAddress;
        }
        
        bsdPanel::Net::IpAddress & Host::getAddress() const
        {
            return (*ipAddress);
        }
    } // end namespace Dns
} // end namespace bsdPanel