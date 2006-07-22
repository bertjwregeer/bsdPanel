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

#ifndef BSDPANEL_DNS_MAILEXCHANGE_H
#define BSDPANEL_DNS_MAILEXCHANGE_H

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

//TODO: Check this file to make sure it is complete
// dont forget to add the distance field to the constructors

namespace bsdPanel
{
    namespace Dns
    {
        class MailExchange : public Host
        {
            public:
                MailExchange();
                MailExchange(const MailExchange &);
                MailExchange(const bsdPanel::Net::DomainName &);
                MailExchange(const bsdPanel::Net::DomainName &, const unsigned long);
                MailExchange(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &);
                MailExchange(const bsdPanel::Net::DomainName &, const std::string &);
                MailExchange(const bsdPanel::Net::DomainName &, const unsigned long, const bsdPanel::Net::IpAddress &);
                MailExchange(const bsdPanel::Net::DomainName &, const unsigned long, const std::string &);
                MailExchange(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &, const unsigned int);
                MailExchange(const bsdPanel::Net::DomainName &, const std::string &, const unsigned int);
                MailExchange(const bsdPanel::Net::DomainName &, const unsigned long, const bsdPanel::Net::IpAddress &, const unsigned int);
                MailExchange(const bsdPanel::Net::DomainName &, const unsigned long, const std::string &, const unsigned int);
                MailExchange(const std::string &);
                MailExchange(const std::string &, const unsigned long);
                MailExchange(const std::string &, const bsdPanel::Net::IpAddress &);
                MailExchange(const std::string &, const std::string &);
                MailExchange(const std::string &, const unsigned long, const bsdPanel::Net::IpAddress &);
                MailExchange(const std::string &, const unsigned long, const std::string &);
                MailExchange(const std::string &, const bsdPanel::Net::IpAddress &, const unsigned int);
                MailExchange(const std::string &, const std::string &, const unsigned int);
                MailExchange(const std::string &, const unsigned long, const bsdPanel::Net::IpAddress &, const unsigned int);
                MailExchange(const std::string &, const unsigned long, const std::string &, const unsigned int);
                virtual ~MailExchange();
                virtual bool isValid() const;
                virtual MailExchange & operator=(const MailExchange &);
                virtual bool operator==(const MailExchange &) const;
                
                //friend std::istream & operator>>(std::istream &, MailExchange &);
            
            protected:
                virtual std::ostream & output(std::ostream &) const;
                virtual unsigned int getDistance() const;
                unsigned int distance;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif
