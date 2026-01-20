/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 

Constraints:

    * 1 <= s.length <= 10^5
    * s consists of only lowercase English letters.


*/

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