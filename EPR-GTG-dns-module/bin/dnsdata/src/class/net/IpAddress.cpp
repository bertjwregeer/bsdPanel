#include <iostream>
#include <string>

#include "IpAddress.h"

bsdPanelNet::IpAddress::IpAddress() {
    octet[0] = 127;
    octet[1] = 0;
    octet[2] = 0;
    octet[3] = 1;
}

bsdPanelNet::IpAddress::IpAddress(std::string& addr) {
    // OK we need to split the address into its parts
    std::stack<std::string> parts = addr.split(deliniator);
    
    // Now we need to check to make sure the parts are valid
    for (int i = 0; i < parts.length(); i++) {
        try {
            unsigned int part = parts.index(i);
            if (part >= 0 && part <= 255) {
                // we have a valid number
                octet[i] = part;
            } else {
                // Throw an exception?
                throw bsdPanelNet::IpAddressException("Invalid Address Segment");
            }
        } catch () {
            delete [] octet;        // unsure if this is the correct way to clear the array
            throw bsdPanelNet::IpAddressException("Invalid Address Segment");
        }
    }
    
    // if they are valid lets stick them into the array
    // well we actually did that earlier
}