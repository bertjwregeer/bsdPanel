// Standard Library Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Our Mathematics functions
#include "Math.h"

// Required Net Includes
#include "Net_Address.h"
#include "Net_DomainName.h"

// Dns Heirarchy
#include "Dns_Record.h"

namespace bsdPanel
{
    namespace Dns
    {
        Record::Record() : timeToLive(14400) 
        { 
            name = new bsdPanel::Net::DomainName(); 
        }
        
        Record::Record(const Record & rhs)
        {
            name = new bsdPanel::Net::DomainName(rhs.name);
            timeToLive = rhs.timeToLive;
        }
        
        Record::Record(const bsdPanel::Net::DomainName & dname) : timeToLive(14400)
        {
            name = new bsdPanel::Net::DomainName(dname);
        }
        
        Record::Record(const bsdPanel::Net::DomainName & dname,
                        const unsigned long ttl) : timeToLive(ttl)
        {
            name = new bsdPanel::Net::DomainName(dname);
        }
        
        Record::Record(const std::string & dname) : timeToLive(14400)
        {
            name = new bsdPanel::Net::DomainName(dname);
        }
        
        Record::Record(const std::string & dname, const unsigned long ttl) : timeToLive(ttl)
        {
            name = new bsdPanel::Net::DomainName(dname);
        }
        
        Record::~Record()
        {
            //delete name;
        }
        
        /*
         * Not required as this method is now pure virtual and must be defined by
         * later classes.
        Record & Record::operator=(const Record & rhs)
        {
            if (this == &rhs)
                return *this;
            
            name = new bsdPanel::Net::DomainName(rhs.getName());
            timeToLive = rhs.timeToLive;
            
            if (!isValid())
                throw RecordException(RecordException::INVALID_RECORD);
            
            return *this;
        }*/
        
        /*
         * Not requred as this method is now pure virtual and must be defined by
         * later classes.
        bool Record::operator==(const Record & rhs) const
        {
            if (this == &rhs)
                return true;
            
            if (name == rhs.getName() && timeToLive == rhs.timeToLive)
                return true;
            else
                return false;
        }*/
        
        std::vector<std::string> & Record::split_string(const std::string & string, const char & delim)
        {
            // break string into pieces by the delimiter
            std::vector<std::string> * string_part = new std::vector<std::string>;
            std::string single_part;
            for (int i = 0; i < string.size(); i++)
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
        
        std::ostream & operator<<(std::ostream & os, const Record & rec)
        {
            os << rec.output(os);
            return os;
        }
        
        void Record::output(std::ostream & os) const
        {
            os << name << ":" << timeToLive;
        }
        
        bsdPanel::Net::DomainName & Record::getName() const
        {
            return name;
        }
        
        unsigned long Record::getTimeToLive() const
        {
            return timeToLive;
        }
    } // end namespace Dns
} // end namespace bsdPanel