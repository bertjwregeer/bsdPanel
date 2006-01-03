#include "Dns_DjbDnsReader.h"

namespace bsdPanel
{
    namespace Dns
    {
        DjbDnsReader::DjbDnsReader() : InputReader() { }
        DjbDnsReader::DjbDnsReader(const std::string & filename) : InputReader()
        {
            std::string line;
            std::ifstream zonefile (filename);
            
            if (zonefile.is_open())
            {
                while ( getline(zonefile, line) )
                {
                    parse_Record(line);
                }
            } else {
                throw InputReaderException(InputReaderException.FILE_INPUT_ERROR);
            }
        }
        
        void DjbDnsReader::parse_Record(const std::string & line)
        {
            // we will have to do it a little differently than the bind method
            
        }
        
        
    } // end namespace Dns
} // end namespace bsdPanel
