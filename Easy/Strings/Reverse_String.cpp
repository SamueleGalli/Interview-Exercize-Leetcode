/* 
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

 

Constraints:

    * 1 <= s.length <= 10^5
    * s[i] is a printable ascii character.


*/

#include <iostream>
#include <algorithm>
#include <vector>


class Solution {
public:
    void reverseString(std::vector<char>& s) {
        if (s.size() == 1)
            return;
        size_t i = 0;
        size_t j = s.size() - 1;
        while (i < s.size() / 2)
        {
            char init = s[i];
            char end = s[j];
            s[i] = end;
            s[j] = init;
            j--;
            i++;
        }
    }
};