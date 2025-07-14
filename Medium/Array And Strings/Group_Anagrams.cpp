#include <vector>

class Solution
{
    int valid(std::string word, std::string check)
    {
        size_t i = 0;
        size_t j = 0;
        while (i < check.size())
        {
            while (j < word.size())
            {
                if (word[j] == check[i])
                {
                    word[j] = '0';
                    break;
                }
                j++;
            }
            j = 0;
            i++;
        }
        i = 0;
        while (i < word.size())
        {
            if (word[i] == '0')
                i++;
            else
                return (1);
        }
        return (0);
    }

private:
    std::string find_anagram(std::string check, std::vector<std::string> &anagram, size_t i)
    {
        while (i < anagram.size())
        {
            if (anagram[i].size() == check.size() && anagram[i] != "000")
            {
                if (valid(anagram[i], check) == 0)
                {
                    std::string an = anagram[i];
                    anagram[i] = "000";
                    return (an);
                }
            }
            i++;
        }
        return ("000");
    }

public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::vector<std::vector<std::string>> all_in;
        if (strs.empty())
            return (all_in);
        if (strs.size() == 1)
        {
            all_in.push_back(strs);
            return (all_in);
        }
        for (size_t i = 0; i < strs.size(); i++)
        {
            if (strs[i] == "000")
                continue;
            all_in.push_back({});
            all_in.back().push_back(strs[i]);
            strs[i] = "000";
            while (1)
            {
                std::string anagram = find_anagram(all_in.back()[0], strs, i);
                if (anagram != "000")
                    all_in.back().push_back(anagram);
                else
                    break;
            }
            strs[i] = "000";
        }
        return (all_in);
    }
};