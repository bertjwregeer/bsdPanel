// required functionality
//  create
//  delete
//  assign
//  validate
//  output
//  compare
//
// every dns record has the following information
//  domain name
//  time to live
//
// type specific information
//  start of authority
//      refresh
//      serial
//      hostmaster
//      retry
//      expire
//      negative cache
//  mail exchange
//      distance
//      dns or ip of mailserver

#ifndef BSDPANEL_DNS_STARTOFAUTHORITY_H
#define BSDPANEL_DNS_STARTOFAUTHORITY_H

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


// NOTE
// Included <ctime> to work out the current time for
// use with the serial variable, which will most likely
// use the fairly industry standard YYYYMMDDXX serial format

namespace bsdPanel
{
    namespace Dns
    {
        /**
         * Start of Authority, SOA, Nameserver record.
         */
        class StartOfAuthority : public NameServer
        {
            public:
                /**
                 * Empty default constructor
                 */
                StartOfAuthority();
                
                /**
                 * Copy constructor.
                 * @param rhs StartOfAuthority object to be copied
                 */
                StartOfAuthority(const StartOfAuthority & rhs);
                
                /**
                 * Constructor.
                 * @param dname Domain name for SOA
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ttl Time to live for the record
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned long serial);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr, 
                            const unsigned long serial,
                            const unsigned long refresh);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr, 
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 * @param expire SOA zone expiration time
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 * @param expire SOA zone expiration time
                 * @param cache SOA zone cache time
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                // DomainName, TimeToLive, IpAddress constructors
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ttl Time to live of record
                 * @param ip_addr IP address of the nameserver
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ttl Time to live of record
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned long serial);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ttl Time to live of record
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ttl Time to live of record
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ttl Time to live of record
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 * @param expire SOA zone expiration time
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ttl Time to live of record
                 * @param ip_addr IP address of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 * @param expire SOA zone expiration time
                 * @param cache SOA zone cache time
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                // DomainName, IpAddress, NameServer constructors
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param ns Domain name of the nameserver
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param ns Domain name of the nameserver
                 * @param serial SOA zone serial number
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param ns Domain name of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param ns Domain name of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param ns Domain name of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 * @param expire SOA zone expiration time
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry, 
                            const unsigned long expire);
                
                /**
                 * Constructor.
                 * @param dname Domain name for the SOA
                 * @param ip_addr IP address of the nameserver
                 * @param ns Domain name of the nameserver
                 * @param serial SOA zone serial number
                 * @param refresh SOA zone refresh value
                 * @param retry SOA zone retry value
                 * @param expire SOA zone expiration time
                 * @param cache SOA zone cache time
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                // DomainName, TimeToLive, IpAddress, NameServer constructors
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns);
                // dname, ttl, ip, nameserver, serial
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial);
                // dname, ttl, ip, nameserver, serial, refresh
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                // dname, ttl, ip, nameserver, serial, refresh, retry
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                // dname, ttl, ip, nameserver, serial, refresh, retry, expire
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                // dname, ttl, ip, nameserver, serial, refresh, retry, expire, cache
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const unsigned long ttl,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                            
                // String based constructors
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl);
                
                // domain name, ip address constructors
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr);
                // dname, ip, serial
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const unsigned long serial);
                // dname, ip, serial, refresh
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh);
                // dname, ip, serial, refresh, retry
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                // dname, ip, serial, refresh, retry, expire
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                // dname, ip, serial, refresh, retry, expire, cache
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                // domain name, ttl, ip address constructors
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr);
                // dname, ttl, ip, serial
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const unsigned long serial);
                // dname, ttl, ip, serial, refresh
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh);
                // dname, ttl, ip, serial, refresh, retry
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                // dname, ttl, ip, serial, refresh, retry, expire
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                // dname, ttl, ip, serial, refresh, retry, expire, cache
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                // domain name, ip address, nameserver constructors
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const std::string & ns);
                // dname, ip, nameserver, serial
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial);
                // dname, ip, nameserver, serial, refresh
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                // dname, ip, nameserver, serial, refresh, retry
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                // dname, ip, nameserver, serial, refresh, retry, expire
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                // dname, ip, nameserver, serial, refresh, retry, expire, cache
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                // domain name, ttl, ip address, nameserver constructors
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const std::string & ns);
                // dname, ttl, ip, nameserver, serial
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial);
                // dname, ttl, ip, nameserver, serial, refresh
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                // dname, ttl, ip, nameserver, serial, refresh, retry
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                // dname, ttl, ip, nameserver, serial, refresh, retry, expire
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry, 
                            const unsigned long expire);
                // dname, ttl, ip, nameserver, serial, refresh, retry, expire, cache
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const unsigned long ttl,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry, 
                            const unsigned long expire,
                            const unsigned long cache);
                
                // Constructors that cover the mixed parameters
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const std::string & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const bsdPanel::Net::DomainName & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const std::string & ns);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const std::string & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire);
                /**
                 * Constructor.
                 *
                 */
                StartOfAuthority(const bsdPanel::Net::DomainName & dname,
                            const bsdPanel::Net::IpAddress & ip_addr,
                            const std::string & ns,
                            const unsigned long serial,
                            const unsigned long refresh,
                            const unsigned long retry,
                            const unsigned long expire,
                            const unsigned long cache);
                
                // End of constructors all 90 of them
                virtual ~StartOfAuthority();
                virtual bool isValid() const;
                virtual StartOfAuthority & operator=(const StartOfAuthority & rhs);
                virtual bool operator==(const StartOfAuthority & rhs) const;
                virtual void updateSerial();
                
                //friend std::istream & operator>>(std::istream &, StartOfAuthority &);
                
                            
            protected:
                virtual void output(std::istream & os) const;
                virtual std::string & getSoaAdmin() const;
                virtual unsigned long getSerial() const;
                virtual unsigned long getRefresh() const;
                virtual unsigned long getRetry() const;
                virtual unsigned long getExpire() const;
                virtual unsigned long getCache() const;
                virtual unsigned long makeSerial() const;
                std::string soaAdmin;
                unsigned long soaSerial;
                unsigned long soaRefresh;
                unsigned long soaRetry;
                unsigned long soaExpire;
                unsigned long soaCache;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif