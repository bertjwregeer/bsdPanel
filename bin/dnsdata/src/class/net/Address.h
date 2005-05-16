/**
 * Abstract base class to define both IP addresses and Domain Name addresses
 * in a standard base format. This allows the use of polymorphism in lists
 * to dynamically store either of the two more specialised types. This class
 * is never instantiated except for in list circumstances.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */
#ifndef NET_ADDRESS_H
#define NET_ADDRESS_H

#include <iostream>
#include <string>

namespace bsdPanelNet {
    class Address {
    	protected:
            const std::string deliniator;
            virtual std::string checkAddress(const std::string& address);

    	public:
            Address() : deliniator(".") { }
            ~Address() { };
            virtual bool isValid(const std::string& address);
    };
}
#endif
