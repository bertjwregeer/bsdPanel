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

#ifndef DNS_STARTOFAUTHORITY_H
#define DNS_STARTOFAUTHORITY_H

#include <iostream>
#include <string>

#include "NameServer.h"

namespace bsdPanelDns {
    class StartOfAuthority : public bsdPanelDns::NameServer {
        protected:
            std::string soaAdmin;
            int serial;
            int refresh;
            int retry;
            int expire;
            int cache;

        public:
    	    StartOfAuthority();
            StartOfAuthority(bsdPanelNet::DomainName& name, bsdPanelNet::IpAddress const& ipaddr, bsdPanelNet::DomainName const& ns, std::string& soaAdmin, int serial, int refresh, int retry,  int expire, int cache);
            StartOfAuthority(bsdPanelNet::DomainName& name, int timeToLive, bsdPanelNet::IpAddress const& ipaddr, bsdPanelNet::DomainName const& ns, std::string& soaAdmin, int serial, int refresh, int retry,  int expire, int cache);
            ~StartOfAuthority();
            friend std::ostream& operator << (std::ostream& os, const StartOfAuthority& soa);
            //friend std::istream& operator>> (std::istream& is, StartOfAuthority& soa);
    };
}
#endif
