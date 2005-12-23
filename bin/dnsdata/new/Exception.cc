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

#include <iostream>
#include <string>
#include "Exception.h"

namespace bsdPanel {
    Exception::Exception()
    {
        reason = new std::string("Unknown Error");
    }
    
    Exception::Exception(const std::string & theReason)
    {
        reason = new std::string(theReason);
    }
    
    Exception::Exception(const char * const theReason)
    {
        reason = new std::string(theReason);
    }
    
    void Exception::printStackTrace() const
    {
        std::cout << "Stack Trace:\nStack trace would follow\n";
    }
    
    void Exception::printError() const
    {
        std::cout << showError() << std::endl;
    }
    
    std::ostream & operator << (std::ostream & os, const Exception & e)
    {
        os << e.showError();
        return os;
    }
    
    const std::string & Exception::showError() const
    {
        return *reason;
    }
    
    void Exception::setReason(const std::string & why)
    {
        reason = new std::string(why);
    }
    
    void Exception::setReason(const char * const why)
    {
        reason = new std::string(why);
    }
}