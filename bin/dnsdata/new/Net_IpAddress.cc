#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Math.h"
#include "Net_Address.h"
#include "Net_IpAddress.h"
#include "Net_IpAddressException.h"

namespace bsdPanel
{
    namespace Net
    {
        // class IpAddress functions
        IpAddress::IpAddress() : Address()
        {
            address = new std::vector<unsigned short int>;
            try
            {
                address->push_back(127);
                address->push_back(0);
                address->push_back(0);
                address->push_back(1);
            }
            catch (std::exception & e)
            {
                throw IpAddressException(e.what());
            }
            if (!isValid())
                throw IpAddressException(IpAddressException::INVALID_ADDRESS);
        }
        
        IpAddress::IpAddress(const IpAddress & ip_addr)
        {
            delim = ip_addr.getDelim();
            address = new std::vector<unsigned short int>;
            createAddress(ip_addr.getAddress());
            
            if (!isValid())
                throw IpAddressException(IpAddressException::INVALID_ADDRESS);
        }
        
        IpAddress::~IpAddress()
        {
            delete address;
        }
        
        bool IpAddress::isValid() const
        {
            bool check = false;
            if (address->size() > 4)
                return false;
            else
                check = true;
            
            /**
             * Its an unsigned short int, so we are limited to the ipv4 range
             */
            /*
            for (std::size_t i = 0; i < address->size(); i++)
            {
                // Check to see if the int is between the right values
                // if its true then we set check and move on to the 
                // next part. If false then we return out of the function
                // as if one part doesnt match then none of it will.
                if (address->at(i) >= 0 && address->at(i) <= 255)
                    check = true;
                else
                    return false;
            }
            */
            return check;
        }
        
        std::vector<unsigned short int> & IpAddress::getAddress() const
        {
            return *address;
        }
        
        // for use in the copy constructor, most other things will use the <int> version
        void IpAddress::createAddress(const std::vector<unsigned short int> & addr)
        {
            if (address == NULL)
                throw IpAddressException("Memory hasnt been allocated");
            
            try
            {
                for (std::size_t i = 0; i < addr.size(); i++)
                {
                    address->push_back(addr[i]);
                }
            }
            catch (std::exception & e)
            {
                // clean up address. make it null or something
                // throw an IpAddressException on up
                throw IpAddressException(e.what());
            }
        }
        
        void IpAddress::createAddress(const std::vector<int> & addr)
        {
            if (address == NULL)
                throw IpAddressException("Memory hasnt been allocated");
            
            try
            {
                for (std::size_t i = 0; i < addr.size(); i++)
                {
                    address->push_back(addr[i]);
                }
            }
            catch (std::exception & e)
            {
                // clean up address. make it null or something
                // throw an IpAddressException on up
                throw IpAddressException(e.what());
            }
        }
        
        void IpAddress::createAddress(const std::string & addr)
        {
            std::vector<int> int_addr = string2int(addr);
            createAddress(int_addr);
        }
        
        void IpAddress::createAddress(const char * const addr)
        {
            std::string string_addr = addr;
            createAddress(addr);
        }
        
        std::vector<int> & IpAddress::string2int(const std::string & ipaddr)
        {
            std::vector<std::string> new_addr = split_string(ipaddr, delim);
            return string2int(new_addr);
        }
        
        std::vector<int> & IpAddress::string2int(const std::vector<std::string> & ipaddr)
        {
            std::vector<int> * int_part = new std::vector<int>;
            for (std::size_t i = 0; i < ipaddr.size(); i++)
            {
                // get each string portion and convert it to a an integer
                std::string part = ipaddr[i];
                std::reverse(part.begin(), part.end());
                
                // We now have the numbers in reverse order so we
                // can pull them off, multiply them by 10*index and add them
                int number = 0;
                for (std::size_t i = 0; i < part.size(); i++)
                {
                    number += (part.at(i) - 48) * bsdPanel::Math::pow(10, i);
                }
                int_part->push_back(number);
            }
            return *int_part;
        }
        
        void IpAddress::output(std::ostream & os) const
        {
            // loop each of the parts except the last one and append the delimiter
            // only if we arent at the end
            std::vector<unsigned short int>::iterator iter;
            for (iter = address->begin(); iter != address->end(); iter++)
            {
                os << *iter;
                if (iter != address->end())
                    os << delim;
            }
        }
        
        unsigned short int & IpAddress::operator[](std::size_t offset)
        {
            if (address->size() < offset)
                throw IpAddressException(IpAddressException::OUT_OF_BOUNDS);
            else
                return address->at(offset);
        }
        
        unsigned short int IpAddress::operator[](std::size_t offset) const
        {
            if (address->size() < offset)
                throw IpAddressException(IpAddressException::OUT_OF_BOUNDS);
            else
                return address->at(offset);
        }
        
        bool IpAddress::operator==(const IpAddress & rhs)
        {
            if (this == &rhs)
                return true;
            
            bool retval = false;
            if (delim == rhs.delim)
                retval = true;
            else
                return false;
            
            std::vector<unsigned short int> rhs_address = rhs.getAddress();
            for (std::size_t i = 0; i < address->size(); i++)
            {
                if (rhs_address.at(i) == address->at(i))
                    retval = true;
                else
                    return false;
            }
            
            return retval;
        }
        
        IpAddress & IpAddress::operator=(const IpAddress & rhs)
        {
            if (this == &rhs)
                return *this;
            
            // get rid of our old stuff and create new
            delim = rhs.delim;
            address = new std::vector<unsigned short int>;
            createAddress(rhs.getAddress());
            
            if (!isValid())
                throw IpAddressException(IpAddressException::INVALID_ADDRESS);
            
            return *this;
        }
    } // namespace Net
} // namespace bsdPanel