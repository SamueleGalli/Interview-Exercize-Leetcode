#include <iostream>
#include <string>
#include <cstring>
#include <iterator>
class Solution
{
public:

    int find_char(char value, std::string &s)
    {
        for (size_t i = 0;i < s.size();i++)
        {
            if (s[i] == value)
            {
                s.erase(s.begin() + i);
                return (1);
            }
        }
        return(0);
    }
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() == t.size())
        {
            for (std::string::iterator it = t.begin(); it != t.end();)
            {
                if (find_char(*it, s) == 1)
                    it = t.erase(it);
                else
                    return(false);
                //std::cout << "t after deletion = " << t << std::endl;
            }
            return(true);
        }
        return (false);
    }
};