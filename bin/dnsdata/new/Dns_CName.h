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

#ifndef BSDPANEL_DNS_CNAME_H
#define BSDPANEL_DNS_CNAME_H

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
        class CName : public Record
        {
            public:
                CName();
                CName(const CName &);
                CName(const bsdPanel::Net::DomainName &);
                CName(const bsdPanel::Net::DomainName &, const unsigned long);
                CName(const bsdPanel::Net::DomainName &, const bsdPanel::Net::DomainName &);
                CName(const bsdPanel::Net::DomainName &, const unsigned long,
                        const bsdPanel::Net::DomainName &);
                CName(const std::string &);
                CName(const std::string &, const unsigned long);
                CName(const std::string &, const std::string &);
                CName(const std::string &, const unsigned long, const std::string &);
                virtual ~CName();
                virtual bool isValid() const;
                virtual CName & operator=(const CName &);
                virtual bool operator==(const CName &) const;
                
                //friend std::istream & operator>>(std::istream &, CName &);
            
            protected:
                virtual void output(std::ostream &) const;
                virtual bsdPanel::Net::DomainName & getMapping() const;
                bsdPanel::Net::DomainName mapping;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif