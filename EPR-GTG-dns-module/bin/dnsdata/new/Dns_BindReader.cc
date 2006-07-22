#include "Dns_BindReader.h"

namespace bsdPanel
{
    namespace Dns
    {
        BindReader::BindReader() : InputReader() { }
        BindReader::BindReader(const std::string & filename) : InputReader()
        {
            std::string line;
            std::ifstream zonefile (filename);
            if (zonefile.is_open())
            {
                while ( getline(zonefile, line) )
                {
                
                
                    //getline(zonefile, line);
                    parse_Record(line);
                }
            } else {
                throw InputReaderException(InputReaderException.FILE_INPUT_ERROR);
            }
        }
        
        void BindReader::parse_Record(const std::string & line)
        {
            std::istringstream * iss = new std::istringstream();
            
            // base record variables
            std::string name, in, type;
            unsigned long ttl;
            
            iss->str(line);
            
            // create a reference and use that instead of iss
            
            *ins >> name >> ttl >> in >> type;
            
            // choose which type we should use to parse the rest of the
            // record and add it to the Zone object
            
            //void (*parseFunc)(const std::string &, const unsigned int, std::istringstream &);
            
            if (type == 'SOA')
                parse_SOA(name, ttl, inputStream);
            else if (type == 'NS')
                parse_NS(name, ttl, inputStream);
            else if (type == 'A')
                parse_A(name, ttl, inputStream);
            else if (type == 'MX')
                parse_MX(name, ttl, inputStream);
            else if (type == 'CNAME')
                parse_CNAME(name, ttl, inputStream);
            else if (type == 'TXT')
                parse_TXT(name, ttl, inputStream);
            
            // the string stream should be finished with by now
            delete inputStream;
        }
        
        void BindReader::parse_A(const std::string & name, const unsigned long ttl, const std::istringstream &iss)
        {
            std::string ip_address;
            iss >> ip_address;
            
            bsdPanel::Dns::Address * address = new bsdPanel::Dns::Address(
        }
    } // end namespace Dns
} // end namespace bsdPanel