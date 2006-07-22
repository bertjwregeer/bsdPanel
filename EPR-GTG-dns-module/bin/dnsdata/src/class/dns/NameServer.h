/**
 * Class definition of a Domain Name TEXT record.
 * This record type is used for storing pieces of textual 
 * data in, such as SPF information.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#ifndef DNS_NAMESERVER_H
#define DNS_NAMESERVER_H

#include <iostream>
#include <string>

#include "Record.h"

namespace bsdPanelDns {
    class NameServer : public bsdPanelDns::Record {
        protected:
            bsdPanelNet::IpAddress ip;
            bsdPanelNet::DomainName nameserver;

        public:
    	    NameServer();
            NameServer(bsdPanelNet::IpAddress const& ipaddr, bsdPanelNet::DomainName const& ns);
            ~NameServer();
            friend std::ostream& operator << (std::ostream& os, const NameServer& nameserver);
            //friend std::istream& operator>> (std::istream& is, NameServer& nameserver);
    };
}
#endif
