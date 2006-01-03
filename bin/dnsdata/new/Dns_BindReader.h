#ifndef BSDPANEL_BINDREADER_H
#define BSDPANEL_BINDREADER_H

#include <iostream>
#include <sstream>
#include <fstream>

#include "InputReader.h"

namespace bsdPanel
{
    namespace Dns
    {
        class BindReader : public InputReader
        {
            public:
                BindReader();
                BindReader(const BindReader&);
                BindReader(const std::string & filename);
                // all functions in here need to be pure virtual
                // that is
                // virtual type function(arg1, arg2) = 0;
                
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
                virtual void parse_A(const std::string & name,
                        const unsigned int ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_Alias(const std::string & name,
                        const unsigned int ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_CNAME(const std::string & name,
                        const unsigned int ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_NS(const std::string & name,
                        const unsigned int ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_SOA(const std::string & name,
                        const unsigned int ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_TXT(const std::string & name,
                        const unsigned int ttl,
                        const std::istringstream & iss) = 0;
                
                virtual void parse_MX(const std::string & name,
                        const unsigned int ttl,
                        const std::istringstream & iss) = 0;
    
        }
    } // end namespace Dns
} // end namespace bsdPanel
#endif

