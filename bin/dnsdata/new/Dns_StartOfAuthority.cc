// Standard Library Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

// Our Mathematics functions
#include "Math.h"

// Required Net Includes
#include "Net_Address.h"
#include "Net_IpAddress.h"
#include "Net_DomainName.h"

// Dns Heirarchy
#include "Dns_Record.h"
#include "Dns_NameServer.h"
#include "Dns_StartOfAuthority.h"

/**
 * TODO
 *  decide how the default refresh, retry, expire and cache values
 *  should be set...
 *  The best method would probably be defaults are hard coded, but
 *  the actual programs using the class will specify the values
 *  that it wants the record to be created with.
 */

const std::string BSDPANEL_DNS_SOA_ADMIN = STARTOFAUTHORITY_HOSTMASTER;     //< STARTOFAUTHORITY_HOSTMASTER is defined in the class header file
const int BSDPANEL_DNS_SOA_REFRESH  = 7200;     // 2 hours
const int BSDPANEL_DNS_SOA_RETRY    = 3600;     // 1 hour
const int BSDPANEL_DNS_SOA_EXPIRE   = 604800;   // 1 week
const int BSDPANEL_DNS_SOA_CACHE    = 86400;    // 1 day

namespace bsdPanel
{
    namespace Dns
    {
        /**
         * Empty default constructor
         */
        StartOfAuthority::StartOfAuthority() : NameServer()
        {
            soaAdmin    = new std::string(BSDPANEL_DNS_SOA_ADMIN);
            soaSerial   = makeSerial();
            soaRefresh  = BSDPANEL_DNS_SOA_REFRESH;
            soaRetry    = BSDPANEL_DNS_SOA_RETRY;
            soaExpire   = BSDPANEL_DNS_SOA_EXPIRE;
            soaCache    = BSDPANEL_DNS_SOA_CACHE;
        }
        
        /**
         * Copy constructor.
         * @param soa a StartOfAuthority record
         */
        StartOfAuthority::StartOfAuthority(const StartOfAuthority & rhs)
        {
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
            nameserver = new bsdPanel::Net::DomainName(rhs.getNSName());
            
            // Now for this classes fields
            soaAdmin    = new std::string(rhs.getSoaAdmin());
            soaSerial   = rhs.getSerial();
            soaRefresh  = rhs.getRefresh();
            soaRetry    = rhs.getRetry();
            soaExpire   = rhs.getExpire();
            soaCache    = rhs.getCache();
        }
        
        // Main Constructors
        /**
         * Record constructor.
         * Initializes the Record parent class
         * @param dname bsdPanel::Net::DomainName
         */
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname)
                    : NameServer(dname)
        {
            soaAdmin = new std::string(BSDPANEL_DNS_SOA_ADMIN);
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl) : NameServer(dname, ttl)
        {
            soaAdmin = new std::string(BSDPANEL_DNS_SOA_ADMIN);
        }
        
        // DomainName, IpAddress constructors
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr)
                    : NameServer(dname, ip_addr)
        {
            soaAdmin = new std::string(BSDPANEL_DNS_SOA_ADMIN);
        }
        
        // dname, ip, serial
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const unsigned long serial)
                    : NameServer(dname, ip_addr) , soaSerial(serial)
        {
            soaAdmin = new std::string(BSDPANEL_DNS_SOA_ADMIN);
        }
        // dname, ip, serial, refresh
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr, 
                    const unsigned long serial,
                    const unsigned long refresh);
        // dname, ip, serial, refresh, retry
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr, 
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        // dname, ip, serial, refresh, retry, expire
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        // dname, ip, serial, refresh, retry, expire, cache
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        // DomainName, TimeToLive, IpAddress constructors
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr);
        // dname, ttl, ip, serial
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const unsigned long serial);
        // dname, ttl, ip, serial, refresh
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh);
        // dname, ttl, ip, serial, refresh, retry
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        // dname, ttl, ip, serial, refresh, retry, expire
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        // dname, ttl, ip, serial, refresh, retry, expire, cache
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        // DomainName, IpAddress, NameServer constructors
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns);
        // dname, ip, nameserver, serial
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial);
        // dname, ip, nameserver, serial, refresh
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        // dname, ip, nameserver, serial, refresh, retry
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        // dname, ip, nameserver, serial, refresh, retry, expire
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry, 
                    const unsigned long expire);
        // dname, ip, nameserver, serial, refresh, retry, expire, cache
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        // DomainName, TimeToLive, IpAddress, NameServer constructors
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns);
        // dname, ttl, ip, nameserver, serial
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial);
        // dname, ttl, ip, nameserver, serial, refresh
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        // dname, ttl, ip, nameserver, serial, refresh, retry
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        // dname, ttl, ip, nameserver, serial, refresh, retry, expire
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        // dname, ttl, ip, nameserver, serial, refresh, retry, expire, cache
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const unsigned long ttl,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
                    
        // String based constructors
        StartOfAuthority::StartOfAuthority(const std::string & dname);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl);
        
        // domain name, ip address constructors
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr);
        // dname, ip, serial
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const unsigned long serial);
        // dname, ip, serial, refresh
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh);
        // dname, ip, serial, refresh, retry
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        // dname, ip, serial, refresh, retry, expire
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        // dname, ip, serial, refresh, retry, expire, cache
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        // domain name, ttl, ip address constructors
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr);
        // dname, ttl, ip, serial
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const unsigned long serial);
        // dname, ttl, ip, serial, refresh
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh);
        // dname, ttl, ip, serial, refresh, retry
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        // dname, ttl, ip, serial, refresh, retry, expire
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        // dname, ttl, ip, serial, refresh, retry, expire, cache
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        // domain name, ip address, nameserver constructors
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const std::string & ns);
        // dname, ip, nameserver, serial
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial);
        // dname, ip, nameserver, serial, refresh
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        // dname, ip, nameserver, serial, refresh, retry
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        // dname, ip, nameserver, serial, refresh, retry, expire
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        // dname, ip, nameserver, serial, refresh, retry, expire, cache
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        // domain name, ttl, ip address, nameserver constructors
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const std::string & ns);
        // dname, ttl, ip, nameserver, serial
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial);
        // dname, ttl, ip, nameserver, serial, refresh
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        // dname, ttl, ip, nameserver, serial, refresh, retry
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        // dname, ttl, ip, nameserver, serial, refresh, retry, expire
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry, 
                    const unsigned long expire);
        // dname, ttl, ip, nameserver, serial, refresh, retry, expire, cache
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const unsigned long ttl,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry, 
                    const unsigned long expire,
                    const unsigned long cache);
        
        // Constructors that cover the mixed parameters
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const bsdPanel::Net::DomainName & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const std::string & ns);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const std::string & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire);
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                    const bsdPanel::Net::IpAddress & ip_addr,
                    const std::string & ns,
                    const unsigned long serial,
                    const unsigned long refresh,
                    const unsigned long retry,
                    const unsigned long expire,
                    const unsigned long cache);
    } // end namespace Dns
} // end namespace bsdPanel