/**
 * DJBdns Specific implementation of the TEXT record type
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @licence http://licence.got-w00t.co.uk/project Project
 * @Revision: $Id$ 
 */

#include <iostream>
#include <string>

#include "Text.h"

bsdPanelDns::Text::Text() {
    // empty constructor
}

bsdPanelDns::Text::Text(const std::string text) {
    contents = text;
}

bsdPanelDns::Text::~Text() {
    delete contents;
}

std::ostream& bsdPanelDns::operator<<(ostream& os, const Text& txt) {
    // Text Record   'fqdn:s:ttl:timestamp:lo
    txt.makeSafe(contents);
    os << "'" << txt.fqdn << ":" << txt.contents << ":" << txt.ttl << ":" << txt.timestamp << ":" << txt.lo << "\n";
}

void bsdPanelDns::Text::makeSafe(std::string& str) {
    // make the string safe for djbdns, convert symbols to octal
}