/**
 * DomainName class implementation. 
 *
 * @author Geoffrey Garside <ggarside@got-w00t.co.uk>
 * @author Jan-Willem Regeer <xistence@x-istence.com>
 * @version 0.1
 * @copyright Geoffrey Garside 2005
 * @copyright X-Istence.com 2005
 * @license http://license.got-w00t.co.uk/project Project
 */

#include <iostream>
#include <sstream>
#include <ifstream>
#include <string>
#include <vector>
#include <algorithm>

#include "DomainName.h"
#include "DomainNameException.h"

bsdPanelNet::DomainName::DomainName() : name(std::string("example.net")) {
        initCheckVars();
}

bsdPanelNet::DomainName::DomainName(const std::string& domainName) {
    initCheckVars();
    try {
        domainName = checkAddress(domainName);
    } catch (DomainNameException e) {
        domainName = "example.com";
    }
    name = domainName;
}

bsdPanelNet::DomainName::~DomainName() {
	// There is no desctructor needed yet
}

bool bsdPanelNet::DomainName::isValid(std::string const& address) {
    try {
        address = checkAddress(address);
        return true;
    } catch (DomainNameException e) {
        return false;
    }
}

std::string bsdPanelNet::DomainName::hostmaster() {
	std::string out = Òhostmaster.Ó;
	out.append(domainName);
	return out;
}

/** see page 143 of C++ for Java Programmers for another split function */
std::vector<std::string> bsdPanelNet::DomainName::splitName(const std::string& address) {
        std::string t;
        std::vector<std::string> v;
        std::istringstream strm(address);
        while (std::getline(strm, t, delimiter)) {
                v.push_back(t);
        }
        
        return v;
}

/**
 * Properly ported to C++ now.
 */
std::string bsdPanelNet::DomainName::checkAddress(const std::string& address) {
    std::vector<std::string> parts = splitName(address);
        
    // weeeeeee this should actually work :-P
    std::vector<std::string>::iterator code =
        find (domainCode.begin(), domainCode.end(), parts.at(parts.size() - 1));
    if ( code != domainCode.end() ) {
        return address;
    } else {
        throw DomainNameException("Domain suffix invalid");
    }
}

std::ostream& bsdPanelNet::operator << (std::ostream& os, const DomainName& domainName) {
        os << domainName.name;
}

// /*/TODO/*/ This is an expensive operation. Should be done once, after that it should be a global variable which can be used over and over again
void bsdPanelNet::DomainName::initCheckVars() {
    if (domainCode.empty())
        initDomainCodes();
}

// OK, we now use a file to store the stuff :D
void bsdPanelNet::DomainName::initDomainCodes() {
    // Ok, we need to open the file with the codes and
    // store them into the domainCode vector
    std::ifstream codes;
    codes.open("DomainCodes.dat");
    
    std::string code;
    
    if (codes.is_open()) {
        // file is open, we can now read the contents into the vector
        do { 
            std::getline(codes, code);
            domainCode.push_back(code);
        } while (!codes.eof());

    } else {
        // Error reading file, we need to decide how to deal with this
        // Throw an exception :P
    }
    
    codes.close();
}
