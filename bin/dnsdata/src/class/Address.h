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
            ~Address() { delete delimiter; };
            virtual static boolean isValid(const std::string& address);
    };
}
#endif