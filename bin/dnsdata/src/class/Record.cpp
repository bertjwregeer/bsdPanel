/**
 * Implementation of the base Record type
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @licence http://licence.got-w00t.co.uk/project Project
 * @Revision: $Id$ 
 */
 
#include <iostream>
#include <string>

#include "Record.h"

Record::Record(DomainName& name) : ttl(14400) {
    fqdn = new DomainName(name);
}

Record::Record(DomainName& name, int timeToLive) ttl(timeToLive) {
    fqdn = new DomainName(name);
}

Record::Record(Record& record) {
    fqdn = new DomainName(record.fqdn);
    ttl = record.ttl;
}

Record::~Record() {
    delete fqdn;
}