#include <iostream>
#include <string>
#include <unordered_set>
#include <cstring>

class Solution
{
public:
    bool find_next(std::string s, size_t i, char value)
    {
        while (i < s.size())
        {
            i++;
            std::cout << value << " == " << s[i] << std::endl;
            if (value == s[i])
                return (true);
        }
        return(false);
    }

    int firstUniqChar(std::string s)
    {
        std::unordered_set<char> test;
        for (size_t i = 0;i < s.size(); i++)
        {
            if (!test.count(s[i]) && find_next(s, i, s[i]) == false)
                return (i);   
            else
                test.insert(s[i]);
        }
        return (-1);
    }
};