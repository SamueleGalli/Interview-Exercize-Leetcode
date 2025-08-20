#include <vector>
#include <algorithm>
#include <map>
#include <utility>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::map<int, int> ordered;
        for (int value : nums)
        {
            ordered[value]++;
        }

        std::vector<std::pair<int, int>> paired;
        for (std::pair<int, int> pair : ordered)
        {
            paired.push_back({pair.first, pair.second});
        }
        std::vector<int> result;
        //[valori esterni],(elementi di pairs){funzione speciale Lambda}
        std::sort(paired.begin(), paired.end(), [](std::pair<int, int> &a, std::pair<int, int> &b)
        {
            if (b.second > a.second)
                return (false);
            return (true); 
        });
        for (int i = 0; i < k; i++)
        {
            result.push_back(paired[i].first);
        }
        return (result);
    }
};