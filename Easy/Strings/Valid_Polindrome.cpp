/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

 

Constraints:

    * 1 <= s.length <= 2 * 10^5
    * s consists only of printable ASCII characters.


*/
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