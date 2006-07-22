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

#ifndef DNS_MAILEXCHANGE_H
#define DNS_MAILEXCHANGE_H

#include <iostream>
#include <string>

#include "Host.h"

namespace bsdPanelDns {
    class MailExchange : public bsdPanelDns::Host {
        protected:
            int distance;
        
        public:
    	    MailExchange();
            MailExchange(bsdPanelNet::IpAddress const& pIp);
            ~MailExchange();
            friend std::ostream& operator << (std::ostream& os, const MailExchange& mx);
            //friend std::istream& operator>> (std::istream& is, MailExchange& mx);
    };
}
#endif
