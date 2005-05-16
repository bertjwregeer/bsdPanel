/**
 * Dns Data output formatter
 * Takes a standard formatted TAB delimited string and 
 * formats it into the correct form for a specific DNS
 * server type.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 */

#include <iostream>
#include <string>

namespace bsdPanel {
    class OutputFormatter {
        public:
            static std::string convert(const std::string& str);
    };
}