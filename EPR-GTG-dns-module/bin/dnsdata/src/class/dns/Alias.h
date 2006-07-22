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

#ifndef DNS_ALIAS_H
#define DNS_ALIAS_H

#include <iostream>
#include <string>

#include "Host.h"

namespace bsdPanelDns {
    class Alias : public bsdPanelDns::Host {
        public:
    	    Alias();
            Alias(bsdPanelNet::IpAddress const& pIp);
            ~Alias();
            friend std::ostream& operator << (std::ostream& os, const Alias& alias);
            //friend std::istream& operator>> (std::istream& is, Alias& alias);
    };
}
#endif
