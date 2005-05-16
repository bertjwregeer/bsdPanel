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

#ifndef DNS_CNAME_H
#define DNS_CNAME_H

#include <iostream>
#include <string>

#include "Record.h"

namespace bsdPanelDns {
    class CName : public bsdPanelDns::Record {
        protected:
            bsdPanelNet::DomainName mapping;

        public:
    	    CName();
            CName(bsdPanelNet::DomainName const& mapping);
            ~CName();
            friend std::ostream& operator << (std::ostream& os, const CName& mapping);
            //friend std::istream& operator>> (std::istream& is, CName& mapping);
    };
}
#endif
