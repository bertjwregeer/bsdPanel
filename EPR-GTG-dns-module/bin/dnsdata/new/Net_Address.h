#ifndef BSDPANEL_NET_ADDRESS_H
#define BSDPANEL_NET_ADDRESS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Math.h"

namespace bsdPanel
{
    namespace Net
    {
        class Address
        {
            public:
                Address();
                Address(const char aDelim);
                Address(const Address &);
                virtual ~Address();
                virtual std::vector<std::string> & split_string(const std::string &, const char &);
                virtual bool isValid() const = 0;
                virtual Address & operator=(const Address &);
                virtual bool operator==(const Address &);
                virtual std::string & asString() const = 0;
                
                friend std::ostream & operator<<(std::ostream &, const Address &);
                
            protected:
                virtual std::ostream & output(std::ostream &) const;
                virtual char getDelim() const;
                char delim;
        };
    } // namespace Net
} // namespace bsdPanel
#endif
