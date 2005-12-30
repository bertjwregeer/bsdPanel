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

#ifndef STARTOFAUTHORITY_HOSTMASTER
#define STARTOFAUTHORITY_HOSTMASTER "hostmaster"
#endif

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


// NOTE
// Included <ctime> to work out the current time for
// use with the serial variable, which will most likely
// use the fairly industry standard YYYYMMDDXX serial format

extern const std::string BSDPANEL_DNS_SOA_ADMIN;
extern const unsigned long BSDPANEL_DNS_SOA_REFRESH;
extern const unsigned long BSDPANEL_DNS_SOA_RETRY;
extern const unsigned long BSDPANEL_DNS_SOA_EXPIRE;
extern const unsigned long BSDPANEL_DNS_SOA_CACHE;

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
                StartOfAuthority();
                StartOfAuthority(const StartOfAuthority &);
                
                StartOfAuthority(const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &, const unsigned long,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const bsdPanel::Net::DomainName &, 
                        const bsdPanel::Net::IpAddress &, 
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &,
                        const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const bsdPanel::Net::DomainName &, 
                        const unsigned long, 
                        const bsdPanel::Net::IpAddress &, 
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &, 
                        const unsigned long, 
                        const std::string &, 
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &, const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &, const std::string &, const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &, const std::string &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const bsdPanel::Net::DomainName &, const unsigned long, const bsdPanel::Net::IpAddress &, const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &, const unsigned long, const bsdPanel::Net::IpAddress &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &, const unsigned long, const std::string &, const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const bsdPanel::Net::DomainName &, const unsigned long, const std::string &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const unsigned long,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const std::string &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const bsdPanel::Net::IpAddress &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const std::string &, const unsigned long, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const unsigned long, const bsdPanel::Net::IpAddress &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const std::string &, const std::string &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const bsdPanel::Net::IpAddress &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const std::string &, const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const bsdPanel::Net::IpAddress &, const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                StartOfAuthority(const std::string &, const unsigned long, const std::string &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const unsigned long, const bsdPanel::Net::IpAddress &, const std::string &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const unsigned long, const std::string &, const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                StartOfAuthority(const std::string &, const unsigned long, const bsdPanel::Net::IpAddress &, const bsdPanel::Net::DomainName &,
                        const std::string,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long,
                        const unsigned long);
                
                virtual ~StartOfAuthority();
                virtual bool isValid() const;
                virtual StartOfAuthority & operator=(const StartOfAuthority & rhs);
                virtual bool operator==(const StartOfAuthority & rhs) const;
                virtual void updateSerial();
                
                //friend std::istream & operator>>(std::istream &, StartOfAuthority &);
                
                            
            protected:
                virtual std::ostream & output(std::ostream & os) const;
                virtual std::string & getSoaAdmin() const;
                virtual unsigned long getSerial() const;
                virtual unsigned long getRefresh() const;
                virtual unsigned long getRetry() const;
                virtual unsigned long getExpire() const;
                virtual unsigned long getCache() const;
                virtual unsigned long makeSerial() const;
                std::string *soaAdmin;
                unsigned long soaSerial;
                unsigned long soaRefresh;
                unsigned long soaRetry;
                unsigned long soaExpire;
                unsigned long soaCache;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif
