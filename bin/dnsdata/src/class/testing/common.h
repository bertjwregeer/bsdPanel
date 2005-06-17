std::vector<std::string> & split_string(const std::string & string, const char & delim)
{
    // break string into pieces by the delimiter
    std::vector<std::string> * string_part = new std::vector<std::string>;
    std::string single_part;
    for (int i = 0; i < string.size(); i++)
    {
        if (delim == string[i])
        {
            string_part->push_back(single_part);
            single_part = "";
            i++;        // skip over the '.'
        }
        single_part += string[i];
    }
    string_part->push_back(single_part);     // catch the last part of the address
    return *string_part;
}