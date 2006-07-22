#include <iostream>
#include <string>

#include "Address.h"

bsdPanelDns::Address::Address() {
    super("example.com", 86400, "192.168.0.10");
}