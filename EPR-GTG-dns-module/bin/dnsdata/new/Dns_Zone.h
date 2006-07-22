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

#ifndef BSDPANEL_DNS_ZONE_H
#define BSDPANEL_DNS_ZONE_H

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
#include "Dns_Address.h"
#include "Dns_Alias.h"
#include "Dns_MailExchange.h"
#include "Dns_NameServer.h"
#include "Dns_StartOfAuthority.h"
#include "Dns_CName.h"
#include "Dns_Text.h"

namespace bsdPanel
{
    namespace Dns
    {
        // Begin Zone class
        class Zone
        {
            public:
                Zone();
                Zone(const Zone &);
                
                // worker methods
                void addRecord(const RECORD_TYPE, const std::string &, const std::string &, const unsigned int);
                void addRecord(const bsdPanel::Dns::Record &);
            protected:
                enum RECORD_TYPE {
                    STARTOFAUTHORITY,
                    NAMESERVER,
                    ADDRESS,
                    ALIAS,
                    MAILEXCHANGE,
                    CNAME,
                    TEXT
                };
        }; // end class Zone
    } // end namespace Dns
} // end namespace bsdPanel
#endif
