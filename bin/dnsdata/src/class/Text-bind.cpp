/**
 * BiND Specific implementation of the TEXT record type
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

Text::Text() {
    // empty constructor
}

Text::Text(const string text) {
    contents = text;
}

Text::~Text() {
    delete contents;
}

std::ostream& operator<< (ostream& os, const Text& txt) {
    // Text Record    <fqdn>    IN TXT    "text information"
    os << txt.fqdn << "\tIN TXT\t\"" << txt.contents << "\"\n";
}

Text::makeSafe(string& str) {
    // this doesnt actually do anything in bind, but we sorta
    // have to do something to it, at least define and so on.
}