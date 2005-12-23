#include "Net_IpAddressException.h"

namespace bsdPanel
{
    namespace Net
    {
        IpAddressException::IpAddressException() : Exception("Unknown Reason")
        {
        }
        
        IpAddressException::IpAddressException(const std::string & why) : Exception(why)
        {
        }
        
        IpAddressException::IpAddressException(const std::exception & e) : Exception(e.what())
        {
        }
        
        IpAddressException::IpAddressException(const int & e)
        {
            if (e == MEMORY_ALLOCATION)
            {
                setReason("Memory Allocation Problem");
            } 
            else if (e == PUSH_SEGMENT)
            {
                setReason("Problem storing address segment");
            }
            else if (e == INVALID_ADDRESS)
            {
                setReason("Address is not valid");
            }
            else if (e == OUT_OF_BOUNDS)
            {
                setReason("Storage access error, out of bounds");
            }
        }
    } // namespace Net
} // namespace bsdPanel