/**
 * Domain Name Exception
 * This enables us to throw an easily defined exception for the Domain Name
 * class. Examples of usage would be if a domain name suffix is invalid.
 * This should typically be thrown only by the Domain Name class and is
 * included by that file for this reason.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @link class Exception
 * @link class AddressException
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#ifndef NET_DOMAINNAME_EXCEPTION_H
#define NET_DOMAINNAME_EXCEPTION_H

#include <iostream>
#include <string>

#include "AddressException.h"

namespace bsdPanelNet {
    class DomainNameException : public bsdPanelNet::AddressException {
        public:
            DomainNameException() { reason = "Error: Undefined"; }
            DomainNameException(std::string & why) { reason = why; }
            DomainNameException(DomainNameException & why) { reason = why.reason; }
            
            void operator = (DomainNameException & why) { reason = why.reason; }
            operator std::string () { return reason; }
    };
}
#endif
