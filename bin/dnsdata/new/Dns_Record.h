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

#ifndef BSDPANEL_DNS_RECORD_H
#define BSDPANEL_DNS_RECORD_H

// Standard Library Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Our Mathematics functions
#include "Math.h"

// Required Net Includes
#include "Net_Address.h"
#include "Net_DomainName.h"

namespace bsdPanel
{
    namespace Dns
    {
        class Record
        {
            public:
                Record();
                //Record(const Record &);
                Record(const bsdPanel::Net::DomainName &);
                Record(const bsdPanel::Net::DomainName &, const unsigned long);
                Record(const std::string &);
                Record(const std::string &, const unsigned long);
                virtual ~Record();
                virtual std::vector<std::string> & split_string(const std::string &, const char &);
                virtual bool isValid() const = 0;
                virtual Record & operator=(const Record &) = 0;
                virtual bool operator==(const Record &) const = 0;
                
                friend std::ostream & operator<<(std::ostream &, const Record &);
                //friend std::istream & operator>>(std::istream &, Record &);
            
            protected:
                virtual void output(std::ostream &) const;
                virtual bsdPanel::Net::DomainName & getName() const;
                virtual unsigned long getTimeToLive() const;
                bsdPanel::Net::DomainName name;
                unsigned long timeToLive;    
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif