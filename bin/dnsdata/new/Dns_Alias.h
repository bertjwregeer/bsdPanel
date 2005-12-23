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

#ifndef BSDPANEL_DNS_ALIAS_H
#define BSDPANEL_DNS_ALIAS_H

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
        class Alias : public Host
        {
            public:
                Alias();
                Alias(const Alias &);
                Alias(const bsdPanel::Net::DomainName &);
                Alias(const bsdPanel::Net::DomainName &, const unsigned long);
                Alias(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &);
                Alias(const bsdPanel::Net::DomainName &, const unsigned long,
                        const bsdPanel::Net::IpAddress &);
                Alias(const std::string &);
                Alias(const std::string &, const unsigned long);
                Alias(const std::string &, const bsdPanel::Net::IpAddress &);
                Alias(const std::string &, const unsigned long, const bsdPanel::Net::IpAddress &);
                Alias(const std::string &, const std::string &);
                Alias(const std::string &, const unsigned long, const std::string &);
                virtual ~Alias();
                virtual bool isValid() const;
                virtual Alias & operator=(const Alias &);
                virtual bool operator==(const Alias &) const;
                
                //friend std::istream & operator>>(std::istream &, Alias &);
            
            protected:
                virtual void output(std::ostream &) const;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif