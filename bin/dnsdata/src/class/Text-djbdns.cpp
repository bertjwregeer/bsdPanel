#include <iostream>
#include <string>

#include "Text.h"

Text::Text() {
    contents = "";
}

Text::Text(const string text) {
    contents = text;
}

std::ostream& operator<<(ostream& os, const Text& txt) {
    // Text Record   'fqdn:s:ttl:timestamp:lo
    txt.makeSafe(contents);
    os << "'" << txt.fqdn << ":" << txt.contents << ":" << txt.ttl << ":" << txt.timestamp << ":" << txt.lo << "\n";
}

Text::makeSafe(string& str) {
    // make the string safe for djbdns, convert symbols to octal
}