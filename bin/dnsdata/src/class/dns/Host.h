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

#ifndef DNS_HOST_H
#define DNS_HOST_H

#include <iostream>
#include <string>

#include "Record.h"

namespace bsdPanelDns {
    class Host : public bsdPanelDns::Record {
        protected:
            bsdPanelNet::IpAddress ip;

        public:
    	    Host();
            Host(bsdPanelNet::IpAddress const& pIp);
            ~Host();
            friend std::ostream& operator << (std::ostream& os, const Host& host);
            //friend std::istream& operator>> (std::istream& is, Host& host);
    };
}
#endif
