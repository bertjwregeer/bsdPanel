#ifndef NET_NETADDRESS_H
#define NET_NETADDRESS_H

#include <iostream>
#include <string>

class NetAddress {
	protected:
        const std::string delimiter;
        virtual std::string checkAddress(const std::string& address);
	
	public:
        NetAddress() : delimiter(".") { }
        ~NetAddress() { delete delimiter; };
        virtual static boolean isValid(const std::string& address);
};

#endif