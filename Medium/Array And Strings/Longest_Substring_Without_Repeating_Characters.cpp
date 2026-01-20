/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

Constraints:

    * 0 <= s.length <= 5 * 10^4
    * s consists of English letters, digits, symbols and spaces.

*/

#include <vector>
#include <string>
class Solution
{
private:
    int not_ripetitive(char c, std::vector<char> s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                return (1);
        }
        return (0);
    }

public:
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.empty())
            return (0);
        std::vector<std::vector<char>> subs;
        subs.push_back({});
        subs.back().push_back(s[0]);
        size_t i2 = 1;
        for (size_t i = 1; i < s.size(); i++)
        {
            if (i > 0 && s[i] != s[i - 1] && not_ripetitive(s[i], subs.back()) == 0)
                subs.back().push_back(s[i]);
            else
            {
                if (!subs.empty())
                {
                    subs.push_back({});
                    i = i2;
                    i2++; 
                    subs.back().push_back(s[i]);
                }
            }
        }
        int size = 0;
        for (size_t i = 0; i < subs.size(); i++)
        {
            if (static_cast<int>(subs[i].size()) > size)
                size = static_cast<int>(subs[i].size());
        }
        return (size);
    }
};