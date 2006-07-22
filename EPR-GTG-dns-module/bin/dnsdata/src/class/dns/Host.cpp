#include <iostream>
#include <string>

#include "Host.h"

bsdPanelDns::Host::Host() {
    super();
    ip = new bsdPanelNet::IpAddress();
}

bsdPanelDns::Host::Host(bsdPanelNet::DomainName& name, bsdPanelNet::IpAddress const& ipAddr) {
    super(name);
    ip = new bsdPanelNet::IpAddress(ipAddr);
}

bsdPanelDns::Host::Host(std::string& name, int timeToLive, std::string& ipAddr) {
    super(name, timeToLive);
    ip = new bsdPanelNet::IpAddress(ipAddr);
}