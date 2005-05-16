/**
 * DomainName class
 * This class is used to validate and store domain names. It is also designed
 * to format and return certain domain name zone information in a standard
 * way. Examples include the BiND hostmaster information.
 * This class is core to the operation of the Record Type and is derived from
 * the Address class type.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */
#ifndef NET_DOMAINNAME_H
#define NET_DOMAINNAME_H

#include <iostream>
#include <string>
#include <vector>

#include "Address.h"

namespace bsdPanelNet {
    class DomainName : public bsdPanelNet::Address {
    	private:
            std::string name;
    	    static std::vector<std::string> domainCode;

            // Private member functions
            // /*/TODO/*/ Use one global with the following initialized. This takes up a ton of processing time otherwise
            void initCheckVars();
            void initDomainCodes();
            void destroyCheckVars();

        public:
            DomainName();
            DomainName(const std::string& domainName);
            DomainName(const DomainName& domainName) : name(domainName.name) { domainCount++; }
            ~DomainName();
            friend std::ostream& bsdPanelNet::operator << (std::ostream& os, const DomainName& domainname);
            virtual bool isValid(std::string const& address);
            std::string hostmaster();

        protected:
            virtual std::string checkAddress(const std::string& address);
            virtual std::vector<std::string> splitName(const std::string& address);
    };
}
#endif
