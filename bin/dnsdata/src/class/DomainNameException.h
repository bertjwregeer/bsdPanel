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
