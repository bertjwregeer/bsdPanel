/**
 * Base Exception class from which other exceptions can be
 * derived from. This enables us to use an almost Java style
 * of catch statements.
 * This file should be included into any file which extends or
 * uses the Exception class.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

namespace bsdPanel {
    class Exception {
        protected:
            std::string reason;

        public:
            Exception() : reason("Error") { }
            Exception(std::string & why) : reason(why) { }
            Exception(Exception & why) : reason(why.reason) { }
            ~Exception();

            void operator = (Exception & why) { reason = why.reason; }
            operator std::string () { return reason; }
    };
}
#endif
