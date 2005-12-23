// simple program which tests ip addresses

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "header.h"

bool check_ip(const std::string &);
std::vector<std::string> & split_ip_string(const std::string &);
bool check_ip(const int *, const int);
bool check_ip(const char * const);
char * reverse_string(const std::string &);
std::vector<int> & ip_string_to_int(const std::vector<std::string> &);
int my_pow(int, int);

int main()
{
    int int_ip[] = { 83, 265, 14, 6 };
    std::string string_ip = "83.265.14.6";
    char * char_ip = "83.265.14.6";
    
    std::cout << "string_ip: " << string_ip << std::endl;
    //std::cout << "char_ip: " << char_ip << std::endl;
    //std::cout << "int_ip: " << int_ip[0] << "." << int_ip[1] << "." << int_ip[2] << "." << int_ip[3] << std::endl;
    
    std::cout << "check_ip(string_ip): ";
    if (check_ip(string_ip))
        std::cout << "true\n";
    else
        std::cout << "false\n";
    
    std::cout << "check_ip(char_ip): ";
    if (check_ip(char_ip))
        std::cout << "true\n";
    else
        std::cout << "false\n";
    
    std::cout << "check_ip(int_ip): ";
    if (check_ip(int_ip, sizeof(int_ip)/sizeof(int_ip[0])))
        std::cout << "true\n";
    else
        std::cout << "false\n";
}

bool check_ip(const int * ipaddr, const int size)
{
    bool check = false;
    for (int i = 0; i < size; i++)
    {
        // Check to see if the int is between the right values
        // if its true then we set check and move on to the 
        // next part. If false then we return out of the function
        // as if one part doesnt match then none of it will.
        if (0 <= ipaddr[i] && 255 >= ipaddr[i])
            check = true;
        else
            return false;
    }
    return check;
}

bool check_ip(const char * const ipaddr)
{
    std::string addr = ipaddr;
    return (check_ip(addr));
}

bool check_ip(const std::string & ipaddr)
{
    std::vector<std::string> split = split_string(ipaddr, '.');
    
    // we need to convert the strings into integers
    std::vector<int> int_ipaddr = ip_string_to_int(split);
    
    bool check = false;
    for (int i = 0; i < int_ipaddr.size(); i++)
    {
        // Check to see if the int is between the right values
        // if its true then we set check and move on to the 
        // next part. If false then we return out of the function
        // as if one part doesnt match then none of it will.
        if (0 <= int_ipaddr[i] && 255 >= int_ipaddr[i])
            check = true;
        else
            return false;
    }
    return check;
}

std::vector<std::string> & split_ip_string(const std::string & ipaddr)
{
    // break string into pieces by the '.'
    std::vector<std::string> * string_part = new std::vector<std::string>;
    std::string single_part;
    for (int i = 0, j = 0; i < ipaddr.size(); i++)
    {
        if ('.' == ipaddr[i])
        {
            string_part->push_back(single_part);
            single_part = "";
            i++;        // skip over the '.'
        }
        single_part += ipaddr[i];
    }
    string_part->push_back(single_part);     // catch the last part of the address
    return *string_part;
}

std::vector<int> & ip_string_to_int(const std::vector<std::string> & ipaddr)
{
    std::vector<int> * int_part = new std::vector<int>;
    for (int i = 0; i < ipaddr.size(); i++)
    {
        // get each string portion and convert it to a an integer
        std::string part = ipaddr[i];
        std::reverse(part.begin(), part.end());
        
        // We now have the numbers in reverse order so we
        // can pull them off, multiply them by 10*index and add them
        int number = 0;
        for (int i = 0; i < part.size(); i++)
        {
            number += (part.at(i) - 48) * my_pow(10, i);
        }
        int_part->push_back(number);
    }
    return *int_part;
}

int my_pow(int x, int y)
{
    int ans = 1;
    for (int i = 0; i < y; i++)
    {
        ans = ans * x;
    }
    return ans;
}

/******** Unused Code Segment *************/
char * reverse_string(const std::string & octet)
{
    const char * str = octet.c_str();
    char * nstr = new char[octet.size()];
    for (int i = 0, j = octet.size(); i < octet.size(); i++, j--)
    {
        nstr[i] = str[j];
    }
    return nstr;
}