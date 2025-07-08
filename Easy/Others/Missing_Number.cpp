#include <vector>
#include <algorithm>

class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int check = nums[0];
        if (std::find(nums.begin(), nums.end(), 0) == nums.end())
            return (0);
        for (size_t i = 1; i < nums.size();i++)
        {
    
            if (nums[i] != check + 1)
                return (++check);
            check = nums[i];
        }
        return (check + 1);
    }
};