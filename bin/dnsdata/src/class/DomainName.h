/**
 * DomainName class
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @licence http://licence.got-w00t.co.uk/project Project
 * @Revision: $Id$ 
 */
#ifndef NET_DOMAINNAME_H
#define NET_DOMAINNAME_H

#include <iostream>
#include <string>
#include <vector>

namespace bsdPanelNet {
    class DomainName : public bsdPanelNet::Address {
    	private:
            std::string * name;
    	    std::vector<std::string> countryCode;
            std::vector<std::string> globalCode;
            std::vector<std::string> newNameCode;

            // Private member functions
            // /*/TODO/*/ Use one global with the following initialized. This takes up a ton of processing time otherwise
            void initCheckVars();
            void initCountryCodes();
            void initGlobalCodes();
            void initNewNameCodes();
            void destroyCheckVars();
            //void destroyCountryCodes();
            //void destroyGlobalCodes();
            //void destroyNewNameCodes();

        public:
            DomainName() : name("example.com") { }
            DomainName(const std::string& domainName);
            DomainName(const DomainName& domainName) : name(domainName.name) { }
            ~DomainName();
            virtual friend std::ostream& bsdPanelNet::operator << (std::ostream& os, const DomainName& domainname);
            virtual static bool isValid(const std::string& address);

        protected:
            virtual std::string checkAddress(const std::string& address);
            virtual std::vector<std::string> splitName(const std::string& address);
    };
}
#endif
