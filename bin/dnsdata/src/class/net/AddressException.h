/**
 *
 *
 *
 *
 *
 *
 *
 *
 */

#ifndef NET_ADDRESS_EXCEPTION_H
#define NET_ADDRESS_EXCEPTION_H

#include <iostream>
#include <string>

#include "Exception.h"

namespace bsdPanelNet {
    class AddressException : public bsdPanel::Exception {
        public:
            AddressException() { reason = "Error: Undefined"; }
            AddressException(std::string & why) { reason = why; }
            AddressException(AddressException & why) { reason = why.reason; }
            
            void operator = (AddressException & why) { reason = why.reason; }
            operator std::string () { return reason; }
    };
}
#endif
