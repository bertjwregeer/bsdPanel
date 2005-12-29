#ifndef BSDPANEL_NET_DOMAINNAME_H
#define BSDPANEL_NET_DOMAINNAME_H

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
        class DomainName : public Address
        {
            public:
                DomainName();
                DomainName(const DomainName &);
                virtual ~DomainName();
                virtual bool isValid() const;
                virtual DomainName & operator=(const DomainName &);
                virtual bool operator==(const DomainName &);
                virtual std::string & asString() const;
            
            protected:
                virtual void output(std::ostream &) const;
                virtual std::string & getName() const;
                void load_domain_codes();
                std::string suffix() const;
                std::string * name;
                static std::vector<std::string> * domain_code;
        };
    } // namespace Net
} // namespace bsdPanel
#endif