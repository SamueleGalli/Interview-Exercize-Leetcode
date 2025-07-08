#include <iostream>
#include <string>
#include <iterator>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s)
    {
        if (s.size() == 1)
            return (true);
        for (auto it = s.begin();it != s.end();)
        {
            if (std::isalpha(*it) || std::isalnum(*it))
            {
                *it = std::tolower(*it);
                it++;
            }
            else
                it = s.erase(it);
        }
        std::cout << "string with only to lower character = "<< s << std::endl;
        size_t end = s.size() - 1;
        size_t start = 0;
        while (end > 0 && start < s.size())
        {
            if (s[end] == s[start])
            {
                end--;
                start++;
            }
            else
                return (false);
        }
        return (true);
    }
};