#include <iostream>
#include <string>

#include "Std.h"
#include "Text.h"

Text::Text() {
    contents = "";
}

Text::Text(const string text) {
    contents = text;
}

#ifdef WITH_BIND
Text::operator<<(ostream& os, const Text& txt) {
    // Text Record    <fqdn>    IN TXT    "text information"
    os << fqdn << "\tIN TXT\t\"" << contents << "\"\n";
}
#endif

#ifdef WITH_DJBDNS
Text::operator<<(ostream& os, const Text& txt) {
    // Text Record   'fqdn:s:ttl:timestamp:lo
    makeSafe(contents);
    os << "'" << fqdn << ":" << contents << ":" << ttl << ":" << timestamp << ":" << lo << "\n";
}
#endif

Text::makeSafe(string& str) {
    // make the string safe for djbdns, convert symbols to octal
}