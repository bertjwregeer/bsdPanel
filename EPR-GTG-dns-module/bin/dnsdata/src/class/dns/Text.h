/**
 * Class definition of a Domain Name TEXT record.
 * This record type is used for storing pieces of textual 
 * data in, such as SPF information.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#ifndef DNS_TEXT_H
#define DNS_TEXT_H

#include <iostream>
#include <string>

#include "Record.h"

namespace bsdPanelDns {
    class Text : public bsdPanelDns::Record {
        protected:
            std::string contents;

        public:
    	    Text();
            Text(std::string const& text);
            ~Text();
            friend std::ostream& operator << (std::ostream& os, const Text& txt);
            //friend std::istream& operator>> (std::istream& is, Text& txt);

        private:
            void makeSafe(std::string& str);
    };
}
#endif
