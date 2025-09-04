#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        size_t max = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i > max)
                return (false);
            max = std::max(max, nums[i] + i);
        }
        return (true);
    }
};
