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

#ifndef BSDPANEL_DNS_HOST_H
#define BSDPANEL_DNS_HOST_H

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

namespace bsdPanel
{
    namespace Dns
    {
        class Host : public Record
        {
            public:
                Host();
                Host(const Host &);
                Host(const bsdPanel::Net::DomainName &);
                Host(const bsdPanel::Net::DomainName &, const unsigned long);
                Host(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &);
                Host(const bsdPanel::Net::DomainName &, const std::string &);
                Host(const bsdPanel::Net::DomainName &, const unsigned long, const bsdPanel::Net::IpAddress &);
                Host(const bsdPanel::Net::DomainName &, const unsigned long, const std::string &);
                Host(const std::string &);
                Host(const std::string &, const unsigned long);
                Host(const std::string &, const bsdPanel::Net::IpAddress &);
                Host(const std::string &, const unsigned long, const bsdPanel::Net::IpAddress &);
                Host(const std::string &, const std::string &);
                Host(const std::string &, const unsigned long, const std::string &);
                virtual ~Host();
                virtual bool isValid() const = 0;
                virtual Host & operator=(const Host &) = 0;
                virtual bool operator==(const Host &) const = 0;
                
                //friend std::istream & operator>>(std::istream &, Host &);
            
            protected:
                virtual std::ostream & output(std::ostream &) const;
                virtual bsdPanel::Net::IpAddress & getAddress() const;
                bsdPanel::Net::IpAddress *ipAddress;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif
