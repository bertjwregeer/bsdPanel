#include "Dns_InputReader.h"

namespace bsdPanel
{
    namespace Dns
    {
        InputReader::InputReader() { zone = new bsdPanel::Dns::Zone(); }
        InputReader::InputReader(std::string & filename)
        {
            zone = new bsdPanel::Dns::Zone();
            zoneFilename  = new std::string(filename); 
        }
        
        void InputReader::filename(std::string & filename)
        {
            if ( zoneFilename != NULL) delete zoneFilename;
            zoneFilename = new std::string (filename);
        }
    } // end namespace Dns
} // end namespace bsdPanel
#endif

