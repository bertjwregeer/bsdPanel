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

#include "OutputFormatter.h"

bsdPanel::OutputFormatter::convert(const std::string& str) {
    // lets see if we cant split up the string into its tab segments
    std::vector<std::string> string_bits;
    
    
}