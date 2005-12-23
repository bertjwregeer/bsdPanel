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

#ifndef BSDPANEL_DNS_NAMESERVER_H
#define BSDPANEL_DNS_NAMESERVER_H

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
        class NameServer : public Record
        {
            public:
                NameServer();
                NameServer(const NameServer &);
                NameServer(const bsdPanel::Net::DomainName &);
                NameServer(const bsdPanel::Net::DomainName &, const unsigned long);
                NameServer(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &);
                NameServer(const bsdPanel::Net::DomainName &, const unsigned long,
                            const bsdPanel::Net::IpAddress &);
                NameServer(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &,
                            const bsdPanel::Net::DomainName &);
                NameServer(const bsdPanel::Net::DomainName &, const unsigned long,
                            const bsdPanel::Net::IpAddress &, const bsdPanel::Net::DomainName &);
                NameServer(const std::string &);
                NameServer(const std::string &, const unsigned long);
                NameServer(const std::string &, const std::string &);   // dname, ip_addr
                NameServer(const std::string &, const unsigned long, const std::string &);
                NameServer(const std::string &, const std::string &, const std::string &); // dname, ip_addr, nameserver
                NameServer(const std::string &, const unsigned long, const std::string &,
                            const std::string &);
                
                // Constructors that cover the mixed parameters
                NameServer(const std::string &, const bsdPanel::Net::IpAddress &, const bsdPanel::Net::DomainName &);
                NameServer(const std::string &, const std::string &, const bsdPanel::Net::DomainName &);
                NameServer(const std::string &, const bsdPanel::Net::IpAddress &, const std::string &);
                NameServer(const bsdPanel::Net::DomainName &, const std::string &, const bsdPanel::Net::DomainName &);
                NameServer(const bsdPanel::Net::DomainName &, const std::string &, const std::string &);
                NameServer(const bsdPanel::Net::DomainName &, const bsdPanel::Net::IpAddress &, const std::string &);
                
                virtual ~NameServer();
                virtual bool isValid() const;
                virtual NameServer & operator=(const NameServer &);
                virtual bool operator==(const NameServer &) const;
                
                //friend std::istream & operator>>(std::istream &, NameServer &);
            
            protected:
                virtual void output(std::ostream &) const;
                virtual bsdPanel::Net::IpAddress & getAddress() const;
                virtual bsdPanel::Net::DomainName & getNSName() const;
                bsdPanel::Net::IpAddress ipAddress;
                bsdPanel::Net::DomainName nameserver;
        };
    } // end namespace Dns
} // end namespace bsdPanel
#endif