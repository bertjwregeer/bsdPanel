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

#ifndef BSDPANEL_DNS_TEXT_H
#define BSDPANEL_DNS_TEXT_H

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
        class Text : public Record
        {
            public:
                Text();
                Text(const Text &);
                Text(const bsdPanel::Net::DomainName &);
                Text(const bsdPanel::Net::DomainName &, const unsigned long);
                Text(const bsdPanel::Net::DomainName &, const std::string &);
                Text(const bsdPanel::Net::DomainName &, const unsigned long,
                        const std::string &);
                Text(const std::string &);
                Text(const std::string &, const unsigned long);
                Text(const std::string &, const std::string &);
                Text(const std::string &, const unsigned long, const std::string &);
                virtual ~Text();
                virtual bool isValid() const;
                virtual Text & operator=(const Text &);
                virtual bool operator==(const Text &) const;
                
                //friend std::istream & operator>>(std::istream &, Text &);
            
            protected:
                virtual std::ostream & output(std::ostream &) const;
                virtual std::string & getContent() const;
                std::string *content;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif
