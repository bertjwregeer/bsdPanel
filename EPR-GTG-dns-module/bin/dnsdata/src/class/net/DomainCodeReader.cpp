#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> domainCode;
    
    std::cout << "Opening File" << std::endl;
    
    // Ok, we need to open the file with the codes and
    // store them into the domainCode vector
    std::ifstream dcodes;
    dcodes.open("DomainCodes.dat");
    
    std::string code;
    //char nextcode[128];
    
    if (dcodes.is_open()) {
        // file is open, we can now read the contents into the vector
        while (!dcodes.eof()) {
            dcodes >> code;
            domainCode.push_back(code);
            std::cout << "Adding code: " << code << std::endl;
        }
    } else {
        std::cout << "Error reading file" << std::endl;
    }
    
    int size = domainCode.size();
    std::cout << "Size of domainCode is " << size << std::endl;
}