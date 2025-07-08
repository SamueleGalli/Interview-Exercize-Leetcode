#include <cstddef>

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