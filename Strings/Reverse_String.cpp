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