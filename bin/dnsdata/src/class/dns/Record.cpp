/**
 * Implementation of the base Record type
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */
 
#include <iostream>
#include <string>

#include "Record.h"

bsdPanelDns::Record::Record(DomainName& name) : ttl(14400) {
    fqdn = new bsdPanelNet::DomainName(name);
}

bsdPanelDns::Record::Record(DomainName& name, int timeToLive) ttl(timeToLive) {
    fqdn = new bsdPanelNet::DomainName(name);
}

bsdPanelDns::Record::Record(Record& record) {
    fqdn = new bsdPanelNet::DomainName(record.fqdn);
    ttl = record.ttl;
}

bsdPanelDns::Record::~Record() {
    delete fqdn;
}
