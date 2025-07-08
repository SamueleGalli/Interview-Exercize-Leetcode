#include <algorithm>
#include <vector>
#include <string>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        {
            std::string result = "";
            size_t i = 1;
            bool is_in_all = true;
            if (strs.size() == 1)
                return(strs[0]);
            for (size_t j = 0;j < strs[i].size(); j++)
            {
                char word = strs[0][j];
                while (i < strs.size())
                {
                    if (strs[i][j] == word)
                        i++;
                    else
                    {
                        is_in_all = false;
                        break;
                    }
                }
                if (is_in_all == true)
                    result.push_back(word);
                else
                {
                    is_in_all = true;
                    return(result);
                }
                i = 1;
            }
            return (result);
        }
    }
};