/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

 

Constraints:

    * 1 <= s.length <= 1000
    * s consist of only digits and English letters.

*/
#include <iostream>

class Solution
{
private:
    std::string pol(size_t i, size_t size, std::string s)
    {
        std::string pol;
        size_t j = 0;
        while (i <= size)
        {
            pol += s[i];
            j++;
            i++;
        }
        return (pol);
    }

    std::string is_pol(size_t i, std::string s, size_t size, std::string polindrom)
    {
        size_t i2;
        size_t size2;
        size_t new_pol;
        while (i < s.size() && size > i)
        {
            if (s[i] == s[size])
            {
                size2 = size;
                i2 = i;
                while (s[i] == s[size] && size > 0)
                {
                    i++;
                    size--;
                }
                if (i > size)
                {
                    new_pol = size2 - i2 + 1;
                    if (new_pol > polindrom.size())
                        polindrom = pol(i2, size2, s);
                }
                i = i2;
                size = size2 - 1;
            }
            else
                size--;
        }
        return (polindrom);
    }
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.empty() || s.size() == 1)
            return (s);
        std::string polindrom;
        for (size_t i = 0; i < s.size(); i++)
        {
            polindrom = is_pol(i, s, s.size() -1, polindrom);
        }
        if (polindrom.empty())
            polindrom = s[0];
        return (polindrom);
    }
};