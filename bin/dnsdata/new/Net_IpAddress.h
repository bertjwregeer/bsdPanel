#ifndef BSDPANEL_NET_IPADDRESS_H
#define BSDPANEL_NET_IPADDRESS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Math.h"
#include "Net_Address.h"

namespace bsdPanel
{
    namespace Net
    {
        class IpAddress : public Address
        {
            public:
                IpAddress();
                IpAddress(const IpAddress &);
                virtual ~IpAddress();
                virtual bool isValid() const;
                virtual IpAddress & operator=(const IpAddress &);
                virtual bool operator==(const IpAddress &);
                virtual unsigned short int & operator[](std::size_t);
                virtual unsigned short int operator[](std::size_t) const;
                virtual std::string & asString() const;
            
            protected:
                virtual void output(std::ostream &) const;
                virtual void createAddress(const std::vector<unsigned short int> &);
                virtual void createAddress(const std::vector<int> &);
                virtual void createAddress(const std::string &);
                virtual void createAddress(const char * const);
                virtual std::vector<int> & string2int(const std::string &);
                virtual std::vector<int> & string2int(const std::vector<std::string> &);
                virtual std::vector<unsigned short int> & getAddress() const;
                
                std::vector<unsigned short int> * address;
        };
    }
}
#endif
