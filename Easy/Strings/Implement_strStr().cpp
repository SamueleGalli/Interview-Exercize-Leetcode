/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

 

Constraints:

    * 1 <= haystack.length, needle.length <= 10^4
    * haystack and needle consist of only lowercase English characters.


*/
#include <cstddef>
#include <string>
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        
        int pos = -1;
        size_t j = 0;
        int i_temp = -1;
        for (size_t i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[j])
            {
                if (i_temp == -1)
                    i_temp = i;
                if (j == 0)
                    pos = i;
                j++;
                if (needle[j] == '\0')
                    break;
            }
            else
            {
                if (i_temp != -1)
                    i = i_temp;
                i_temp = -1;
                j = 0;
                pos = -1;
            }
        }
        if (needle[j] != '\0')
            pos = -1;
        return (pos);
    }
};