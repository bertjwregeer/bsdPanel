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

#ifndef BSDPANEL_DNS_ADDRESS_H
#define BSDPANEL_DNS_ADDRESS_H

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
        class Address : public Host
        {
            public:
                Address();
                Address(const Address &);
                Address(const bsdPanel::Net::DomainName &);
                Address(const bsdPanel::Net::DomainName &, const unsigned long);
                Address(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &);
                Address(const bsdPanel::Net::DomainName &, const std::string &);
                Address(const bsdPanel::Net::DomainName &, const unsigned long,
                        const bsdPanel::Net::IpAddress &);
                Address(const bsdPanel::Net::DomainName &, const unsigned long, const std::string &);
                Address(const std::string &);
                Address(const std::string &, const unsigned long);
                Address(const std::string &, const bsdPanel::Net::IpAddress &);
                Address(const std::string &, const unsigned long,
                        const bsdPanel::Net::IpAddress &);
                Address(const std::string &, const std::string &);
                Address(const std::string &, const unsigned long, const std::string &);
                virtual ~Address();
                virtual bool isValid() const;
                virtual Address & operator=(const Address &);
                virtual bool operator==(const Address &) const;

                
                //friend std::istream & operator>>(std::istream &, Address &);
            
            protected:
                virtual std::ostream & output(std::ostream &) const;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif
