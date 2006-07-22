#ifndef BSDPANEL_OUTPUTWRITER_H
#define BSDPANEL_OUTPUTWRITER_H

#include <iostream>

namespace bsdPanel
{
    namespace Dns
    {
        class OutputWriter
        {
            public:
                virtual void write_A() = 0;
                virtual void write_Alias() = 0;
                virtual void write_MX() = 0;
                virtual void write_NS() = 0;
                virtual void write_SOA() = 0;
                virtual void write_CNAME() = 0;
                virtual void write_TXT() = 0;
            
            protected:
                char delimiter;
                std::string * filename;
        }
    } // end namespace Dns
} // end namespace bsdPanel
#endif
