#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Math.h"
#include "Net_Address.h"

namespace bsdPanel
{
    namespace Net
    {
        // class Address Functions  
        Address::Address() : delim('.')
        {
            // empty constructor
        }
        
        Address::Address(const char aDelim) : delim(aDelim)
        {
            // parameter set via initialization
        }
        
        Address::Address(const Address & addr) : delim(addr.delim)
        {
            // copy constructor
        }
        
        Address & Address::operator=(const Address & rhs)
        {
            if (this == &rhs)
                return *this;
            
            // get rid of our old stuff and create new
            delim = rhs.delim;
            return *this;
        }
        
        bool Address::operator==(const Address & rhs)
        {
            if ((this == &rhs) || (delim == rhs.delim))
                return true;
            else
                return false;
        }
        
        std::ostream & operator<<(std::ostream & os, const Address & addr)
        {
            //os << addr.output(os);
            os << "Address Output - This should be overloaded for the other types";
            return os;
        }
        
        void Address::output(std::ostream & os) const
        {
            os << "Address Output - This should be overloaded for the other types";
        }
        
        char Address::getDelim() const
        {
            return delim;
        }
        
        std::vector<std::string> & Address::split_string(const std::string & string, const char & delim)
        {
            // break string into pieces by the delimiter
            std::vector<std::string> * string_part = new std::vector<std::string>;
            std::string single_part;
            for (std::size_t i = 0; i < string.size(); i++)
            {
                if (delim == string[i])
                {
                    string_part->push_back(single_part);
                    single_part = "";
                    i++;        // skip over the delimiter character
                }
                single_part += string[i];
            }
            string_part->push_back(single_part);     // catch the last part of the address
            return *string_part;
        }
    } // namespace Net
} // namespace bsdPanel
