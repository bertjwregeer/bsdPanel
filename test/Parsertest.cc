#include <Parser/Parser.h>
#include <iostream>

int main () {

        bsdPanel::Parser * doParse;
        
        doParse = new bsdPanel::Parser();
        
        doParse->parseMatch(std::string("hello \\w \\t (\\t) (\\t[4,10]) \\\\ \\"));

}