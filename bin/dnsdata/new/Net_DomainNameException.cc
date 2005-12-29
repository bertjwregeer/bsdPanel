#include "Net_DomainNameException.h"

namespace bsdPanel
{
    namespace Net
    {
        DomainNameException::DomainNameException() : Exception("Unknown Reason")
        {
        }
        
        DomainNameException::DomainNameException(const std::string & why) : Exception(why)
        {
        }
        
        DomainNameException::DomainNameException(const std::exception & e) : Exception(e.what())
        {
        }
        
        DomainNameException::DomainNameException(const int & e)
        {
            if (e == MEMORY_ALLOCATION)
            {
                setReason("Memory Allocation Problem");
            } 
            else if (e == INVALID_ADDRESS)
            {
                setReason("Address is not valid");
            }
        }
    } // namespace Net
} // namespace bsdPanel