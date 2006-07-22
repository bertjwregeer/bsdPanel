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

#ifndef DNS_ADDRESS_H
#define DNS_ADDRESS_H

#include <iostream>
#include <string>

#include "Host.h"

namespace bsdPanelDns {
    class Address : public bsdPanelDns::Host {
        public:
    	    Address();
            Address(bsdPanelNet::DomainName& name, int timeToLive, bsdPanelNet::IpAddress const& pIp);
            Address(std::string& name, int timeToLive, std::string& ip);
            ~Address();
            friend std::ostream& operator << (std::ostream& os, const Address& address);
            //friend std::istream& operator>> (std::istream& is, Address& address);
    };
}
#endif
