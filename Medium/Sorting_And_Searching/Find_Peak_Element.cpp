#include <vector>

class Solution
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return (0);
        if (nums.size() == 2)
        {
            if (nums[0] > nums[1])
                return (0);
            else
                return (1);
        }
        nums.push_back(0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                continue;
            if (nums[i - 1] && i + 1 < nums.size())
            if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i])
                return (i);
        }
        return (0);
    }
};