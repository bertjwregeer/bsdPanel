#ifndef NET_ADDRESS_H
#define NET_ADDRESS_H

#include <iostream>
#include <string>

namespace bsdPanelNet {
    class Address {
    	protected:
            const std::string delimiter;
            virtual std::string checkAddress(const std::string& address);

    	public:
            Address() : delimiter(".") { }
            ~Address() { };
            virtual bool isValid(const std::string& address);
    };
}
#endif
