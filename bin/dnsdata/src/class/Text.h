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
        friend std::ostream& operator<< (std::ostream& os, const Text& txt);
        //friend std::istream& operator>> (std::istream& is, Text& txt);
    
    private:
        void make_safe(string& str);
};

#endif