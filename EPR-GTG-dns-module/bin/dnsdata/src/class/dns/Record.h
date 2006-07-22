/**
 * Base Record class from which all the other record types are defined.
 * This is required as in C++ there is no base 'Object' class from which
 * all objects are defined. So we need a nice generic class that we can 
 * then use for things like Lists, Vectors, Stacks and so on and so forth.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#ifndef DNS_RECORD_H
#define DNS_RECORD_H

#include <iostream>
#include <string>

#include "../net/DomainName.h"

namespace bsdPanelDns {
    class Record {
        protected:
            int ttl;
            bsdPanelNet::DomainName * fqdn;

        public:
            Record() : ttl(14400), fqdn() { };
            Record(int timeToLive) : ttl(timeToLive), fqdn() { };
            Record(bsdPanelNet::DomainName& name);
            Record(bsdPanelNet::DomainName& name, int timeToLive);
            Record(std::string& name);
            Record(std::string& name, int timeToLive);
            Record(Record& record);
            virtual ~Record();
    };
}
#endif
