/**
 * Specialized extension of the Address class type. This class is designed
 * to store, validate and process information based on the Ip Address.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */
#ifndef NET_IPADDRESS_H
#define NET_IPADDRESS_H

#include <iostream>
#include <string>

#include <Address.h>

namespace bsdPanelNet {
    class IpAddress : public bsdPanelNet::Address {
    	protected:
            unsigned int octet[4];
            virtual std::string checkAddress(const std::string& address);

    	public:
            IpAddress() : deliniator(".") { }
            IpAddress(std::string& addr) { }
            IpAddress(bsdPanelNet::IpAddress& addr) : octet(addr.octet) { }
            ~IpAddress() { };
            virtual bool isValid(const std::string& address);
    };
}
#endif
