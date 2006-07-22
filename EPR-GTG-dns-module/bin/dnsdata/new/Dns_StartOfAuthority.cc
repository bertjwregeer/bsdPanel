// Standard Library Includes
#include <iostream>
#include <string>
#include <sstream>
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

const std::string BSDPANEL_DNS_SOA_ADMIN      = STARTOFAUTHORITY_HOSTMASTER;     //< STARTOFAUTHORITY_HOSTMASTER is defined in the class header file
const unsigned long BSDPANEL_DNS_SOA_REFRESH  = 7200;     // 2 hours
const unsigned long BSDPANEL_DNS_SOA_RETRY    = 3600;     // 1 hour
const unsigned long BSDPANEL_DNS_SOA_EXPIRE   = 604800;   // 1 week
const unsigned long BSDPANEL_DNS_SOA_CACHE    = 86400;    // 1 day

const unsigned long BSDPANEL_DNS_SOA_SERIAL_BLANK = 0;

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
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                const std::string admin = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const unsigned long ttl,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, 
                const bsdPanel::Net::IpAddress & ip_addr, 
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                const std::string & ip_addr,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, 
                const unsigned long ttl, 
                const bsdPanel::Net::IpAddress & ip_addr, 
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, 
                const unsigned long ttl, 
                const std::string & ip_addr, 
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const std::string & ip_addr, const bsdPanel::Net::DomainName & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const std::string & ip_addr, const std::string & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const std::string & ip_addr, const bsdPanel::Net::DomainName & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const bsdPanel::Net::DomainName & dname, const unsigned long ttl, const std::string & ip_addr, const std::string & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const unsigned long ttl,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const std::string & ip_addr,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const unsigned long ttl, const std::string & ip_addr,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const std::string & ip_addr, const std::string & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const std::string & ip_addr, const bsdPanel::Net::DomainName & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const unsigned long ttl, const std::string & ip_addr, const std::string & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr, const std::string & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const unsigned long ttl, const std::string & ip_addr, const bsdPanel::Net::DomainName & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                const unsigned long serial  = BSDPANEL_DNS_SOA_SERIAL_BLANK,            //< if is null then it will be created to current time
                const unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                const unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                const unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                const unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::StartOfAuthority(const std::string & dname, const unsigned long ttl, const bsdPanel::Net::IpAddress & ip_addr, const bsdPanel::Net::DomainName & ns,
                const std::string admin     = BSDPANEL_DNS_SOA_ADMIN,
                 unsigned long serial  = NULL,            //< if is null then it will be created to current time
                 unsigned long refresh = BSDPANEL_DNS_SOA_REFRESH,
                 unsigned long retry   = BSDPANEL_DNS_SOA_RETRY,
                 unsigned long expire  = BSDPANEL_DNS_SOA_EXPIRE,
                 unsigned long cache   = BSDPANEL_DNS_SOA_CACHE)
                : NameServer(dname, ttl, ip_addr, ns), soaRefresh(refresh), soaRetry(retry),
                soaExpire(expire), soaCache(cache)
        {
            soaAdmin = new std::string(admin);
            
            if (serial == BSDPANEL_DNS_SOA_SERIAL_BLANK)
                soaSerial = makeSerial();
            else
                soaSerial = serial;
        }
        
        StartOfAuthority::~StartOfAuthority()
        {
            delete soaAdmin;
        }
        
        
        bool StartOfAuthority::isValid() const
        {
            if (name->isValid() &&
                ipAddress->isValid() &&
                nameserver->isValid())
                return true;
            else
                return false;
        }
        
        StartOfAuthority & StartOfAuthority::operator=(const StartOfAuthority & rhs)
        {
            if (this == &rhs)
                return *this;
            
            // need to check for existing values and cleanup before assignment
            if (name != NULL) delete name;
            if (ipAddress != NULL) delete ipAddress;
            if (nameserver != NULL) delete nameserver;
            if (soaAdmin != NULL) delete soaAdmin;
            
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.getTimeToLive();
            ipAddress = new bsdPanel::Net::IpAddress(rhs.getAddress());
            nameserver = new bsdPanel::Net::DomainName(rhs.getNSName());
            soaAdmin = new std::string(rhs.getSoaAdmin());
            soaSerial = rhs.getSerial();
            soaRefresh = rhs.getRefresh();
            soaRetry = rhs.getRetry();
            soaExpire = rhs.getExpire();
            soaCache = rhs.getCache();
            
            return *this;
        }
        
        bool StartOfAuthority::operator==(const StartOfAuthority & rhs) const
        {
            if (*name == rhs.getName() &&
                timeToLive == rhs.getTimeToLive() &&
                *ipAddress == rhs.getAddress() &&
                *nameserver == rhs.getNSName() &&
                *soaAdmin == rhs.getSoaAdmin() &&
                soaSerial == rhs.getSerial() &&
                soaRefresh == rhs.getRefresh() &&
                soaRetry == rhs.getRetry() &&
                soaExpire == rhs.getExpire() &&
                soaCache == rhs.getCache())
                return true;
            else
                return false;

        }
        
        void StartOfAuthority::updateSerial() 
        {
            // updates the current serial number
            // first create the date format
            unsigned long newSerial = makeSerial();
            if (soaSerial >= newSerial)
                soaSerial++;
        }
        
        std::ostream & StartOfAuthority::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive << ":" << ipAddress << ":" << nameserver << ":" << soaAdmin << ":" << soaSerial << ":" << soaRefresh << ":" << soaRetry << ":" << soaExpire << ":" << soaCache;
            return os;
        }
        
        std::string & StartOfAuthority::getSoaAdmin() const
        {
            return *soaAdmin;
        }
        
        unsigned long StartOfAuthority::getSerial() const
        {
            return soaSerial;
        }
        
        unsigned long StartOfAuthority::getRefresh() const
        {
            return soaRefresh;
        }
        
        unsigned long StartOfAuthority::getRetry() const
        {
            return soaRetry;
        }
        
        unsigned long StartOfAuthority::getExpire() const
        {
            return soaExpire;
        }
        
        unsigned long StartOfAuthority::getCache() const
        {
            return soaCache;
        }
        
        unsigned long StartOfAuthority::makeSerial() const
        {
            char str[11];
            time_t tm = time(NULL);
            strftime(str, 10, "%Y%m%d%01", localtime(&tm));
            
            // now we have to convert the contents of str to a number
            std::istringstream ins;
            ins.str(str);
            
            unsigned long serial;
            ins >> serial;
            
            return serial;
        }

    } // end namespace Dns
} // end namespace bsdPanel
