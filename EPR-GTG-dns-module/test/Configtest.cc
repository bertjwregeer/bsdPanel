#include <iostream>
#include "bsdpdConfigCont.h"

int main() {
        std::string path = "../cfg/bsdpd";

        bsdPanel::bsdpdConfigCont* container = new bsdPanel::bsdpdConfigCont();
        
        bsdPanel::Config* MyConfig = new bsdPanel::Config(path, container);
        MyConfig->runParse();
}