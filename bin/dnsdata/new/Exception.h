/**
 * Base Exception class from which other exceptions can be
 * derived from. This enables us to use an almost Java style
 * of catch statements.
 * This file should be included into any file which extends or
 * uses the Exception class.
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#ifndef BSDPANEL_EXCEPTION_H
#define BSDPANEL_EXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>

namespace bsdPanel 
{
    class Exception 
    {
        public:
            Exception();
            Exception(const std::string &);
            Exception(const char * const);
            virtual ~Exception() { delete reason; reason = NULL; }
            virtual void printStackTrace() const;
            virtual void printError() const;
            
            friend std::ostream & operator << (std::ostream &, const Exception &);
        
        protected:
            std::string * reason;
            virtual const std::string & showError() const;
            void setReason(const std::string &);
            void setReason(const char * const);
    };
}
#endif