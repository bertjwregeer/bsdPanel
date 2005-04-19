#include <iostream>
#include <string>
#include <vector>
#include <Exec/Exec.h>
#include <bsdPanelInc.h>

int main() {

        std::vector<std::string> blah;
        
        blah.push_back(std::string("/bin/ls"));
        blah.push_back(std::string("-lah"));
        
        bsdPanel::Exec *MyExec = new bsdPanel::Exec(blah);
        MyExec->doExec();
                
        std::string mystring;
        
        while (MyExec->read(mystring) > 0)
                std::cout << mystring << std::endl;
                
return 0;
}
