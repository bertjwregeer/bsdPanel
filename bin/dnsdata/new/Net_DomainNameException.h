/**
 * Domain Name Exception type
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#ifndef BSDPANEL_NET_DOMAINNAMEEXCEPTION_H
#define BSDPANEL_NET_DOMAINNAMEEXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Exception.h"

namespace bsdPanel
{
    namespace Net
    {
        class DomainNameException : public bsdPanel::Exception::Exception
        {
            public:
                DomainNameException();
                DomainNameException(const std::string &);
                DomainNameException(const std::exception &);
                DomainNameException(const int &);
                virtual ~DomainNameException() {}
                
                // Error Codes
                static const int MEMORY_ALLOCATION = 400;
                static const int INVALID_ADDRESS = 401;
                static const int LOAD_DOMAIN_CODE_ERROR = 402;
        };
    } // namespace Net
} // namespace bsdPanel
#endif