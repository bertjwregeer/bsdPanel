#ifndef BSDPANEL_INPUTREADER_H
#define BSDPANEL_INPUTREADER_H

#include <iostream>
#include <sstream>

namespace bsdPanel
{
    namespace Dns
    {
        class InputReader
        {
            public:
                InputReader();
                InputReader(std::string & filename);
                
                virtual void filename(std::string & filename);
                virtual bsdPanel::Dns::Zone & parse() = 0;
                
                // might create an >> extraction operator which
                // will effectively operate as the parse() method
                // This will return the contents into a Zone object
            
            protected:
                // This should be the primary function which obtains the 
                // first pieces of the line and then passes it on to
                // the type functions.
                // A slight exception to this is the DjbDns subclass
                // This should try to get these parts if possible, if
                // not then set strings to null and ints to 0
                // the type function itself will then have to parse
                // out the pieces of the line
                virtual void parse_Record(const std::string & line) = 0;
                
                // this function may need additional work to
                // decide if its actually parsing an alias or
                // not. This in particular for the BindReader
                /**
                 * These functions are being removed as each
                 * reader is going to have a different way of
                 * handling their content. The below functions
                 * are better for BIND parsing that for 
                 * djbDNS parsing due to the differences
                 * in the record definition format.
                 *
                 * While these functions cannot be explicitly
                 * made a requirement they will be defined as
                 * either private or protected functions in any
                 * subclasses. If a method is found to define
                 * these functions such that their parameters
                 * can be individually defined by subclasses
                 * then they will be.
                virtual void parse_A(const std::string & name,
                        const unsigned long ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_Alias(const std::string & name,
                        const unsigned long ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_CNAME(const std::string & name,
                        const unsigned long ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_NS(const std::string & name,
                        const unsigned long ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_SOA(const std::string & name,
                        const unsigned long ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_TXT(const std::string & name,
                        const unsigned long ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_MX(const std::string & name,
                        const unsigned long ttl,
                        const std::istringstream & iss) = 0;
                */
                
                // protected variables.
                bsdPanel::Dns::Zone * zone;
                std::string * zoneFilename;
        }
    } // end namespace Dns
} // end namespace bsdPanel
#endif

