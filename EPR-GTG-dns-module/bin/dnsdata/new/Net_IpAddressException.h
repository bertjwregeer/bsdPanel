/**
 * Ip Address Exception type
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#ifndef BSDPANEL_NET_IPADDRESSEXCEPTION_H
#define BSDPANEL_NET_IPADDRESSEXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Exception.h"

namespace bsdPanel
{
    namespace Net
    {
        class IpAddressException : public bsdPanel::Exception::Exception
        {
            public:
                IpAddressException();
                IpAddressException(const std::string &);
                IpAddressException(const std::exception &);
                IpAddressException(const int &);
                virtual ~IpAddressException() {}
                
                // Error Codes
                static const int MEMORY_ALLOCATION = 400;
                static const int INVALID_ADDRESS = 401;
                static const int OUT_OF_BOUNDS = 402;
                static const int PUSH_SEGMENT = 403;
        };
    } // namespace Net
} // namespace bsdPanel
#endif
