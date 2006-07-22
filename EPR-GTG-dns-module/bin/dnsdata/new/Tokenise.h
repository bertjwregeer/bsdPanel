#include <string>
#include <vector>
#include <algorithm>

void Tokenise(const std::string & theString, std::vector<std::string> & thePieces, 
                const std::string & delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = theString.find_first_not_of(delimiters, 0);
    
    // Find first "non-delimiter".
    string::size_type pos     = theString.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        thePieces.push_back(theString.substr(lastPos, pos - lastPos));
        
        // Skip delimiters.  Note the "not_of"
        lastPos = theString.find_first_not_of(delimiters, pos);
        
        // Find next "non-delimiter"
        pos = theString.find_first_of(delimiters, lastPos);
    }
}