#ifndef DNS_TEXT_H
#define DNS_TEXT_H

#include <iostream>
#include <string>

class Text extends Record {
    protected:
        string contents;
        
    public:
	    Text();
        Text(const string text);
        inline ostream& operator<<(ostream& os, const Text& txt);
        //inline istream& operator>>(istream& is, Text& txt);
    
    private:
        void make_safe(string& str);
};

#endif