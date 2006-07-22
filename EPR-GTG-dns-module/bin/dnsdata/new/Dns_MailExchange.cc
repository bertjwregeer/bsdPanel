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
#include "Dns_MailExchange.h"

//TODO: Check this file to make sure it is complete
// dont forget to add the distance field to the constructors

namespace bsdPanel
{
    namespace Dns
    {
        MailExchange::MailExchange() : Host() , distance(10)
        {
            // empty constructor
        }
        
        MailExchange::MailExchange(const MailExchange & rhs)
        {
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
            distance = rhs.getDistance();
        }
        
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname)
            : Host(dname), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname, 
                                    const unsigned long ttl) : Host(dname, ttl), distance(10)
        {
            // empty constructor, uses parent
        }
                
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname, 
                            const bsdPanel::Net::IpAddress & ip_addr)
                            : Host(dname, ip_addr), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname, 
                            const std::string & ip_addr)
                            : Host(dname, ip_addr), distance(10)
        {
            // empty constructor, uses parent
        }
                
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr) 
                            : Host(dname, ttl, ip_addr), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                            const std::string & ip_addr) 
                            : Host(dname, ttl, ip_addr), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr, const unsigned int dist)
                            : Host(dname, ip_addr), distance(dist)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr, const unsigned int dist)
                            : Host(dname, ip_addr), distance(dist)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname,
                                const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr,
                                const unsigned int dist) : Host(dname, ttl, ip_addr), distance(dist)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const bsdPanel::Net::DomainName & dname,
                                const unsigned long ttl, const std::string & ip_addr,
                                const unsigned int dist) : Host(dname, ttl, ip_addr), distance(dist)
        {
            // empty constructor, uses parent
        }
        
        
        MailExchange::MailExchange(const std::string & dname) : Host(dname), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname, const unsigned long ttl)
                                : Host(dname, ttl), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr)
                            : Host(dname, ip_addr), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname,
                            const std::string & ip_addr)
                            : Host(dname, ip_addr), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname, const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr)
                            : Host(dname, ttl, ip_addr), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname, const unsigned long ttl,
                            const std::string & ip_addr) : Host(dname, ttl, ip_addr), distance(10)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned int dist) : Host(dname, ip_addr), distance(dist)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname, const std::string & ip_addr,
                            const unsigned int dist) : Host(dname, ip_addr), distance(dist)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname, const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr, const unsigned int dist)
                            : Host(dname, ttl, ip_addr), distance(dist)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::MailExchange(const std::string & dname, const unsigned long ttl,
                            const std::string & ip_addr, const unsigned int dist)
                            : Host(dname, ttl, ip_addr), distance(dist)
        {
            // empty constructor, uses parent
        }
        
        MailExchange::~MailExchange()
        {
            // empty destructor, uses parent
        }
        
        bool MailExchange::isValid() const
        {
            if (name->isValid() && ipAddress->isValid())
                return true;
            else
                return false;
        }
        
        MailExchange & MailExchange::operator=(const MailExchange & rhs)
        {
            if (this == &rhs)
                return *this;
            
            if (name != NULL) delete name;
            if (ipAddress != NULL) delete ipAddress;
            
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
            distance = rhs.getDistance();
            
            return *this;
        }
        
        bool MailExchange::operator==(const MailExchange & rhs) const
        {
            if (this == &rhs)
                return true;
            
            if (*name == rhs.getName() &&
                timeToLive == rhs.timeToLive &&
                *ipAddress == rhs.getAddress() &&
                distance == rhs.getDistance())
                return true;
            else
                return false;
        }
        
        std::ostream & MailExchange::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << ipAddress << ":" << distance;
            return os;
        }
        
        unsigned int MailExchange::getDistance() const
        {
            return distance;
        }
    } // end namespace bsdPanel
} // end namespace bsdPanel
