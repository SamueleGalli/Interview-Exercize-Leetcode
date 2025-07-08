#include <vector>
#include <algorithm>
#include <iterator>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 0)
            return (0);
        if (nums.size() == 1)
            return (nums[0]);
        if (nums.size() == 2)
        {
            if (nums[0] > nums[1])
                return (nums[0]);
            else
                return (nums[1]);
        }
        int prev = nums[0];
        int prev_total;
        if (nums[0] > nums[1])
            prev_total = nums[0];
        else
            prev_total = nums[1];
        int total = 0;
        for (size_t i = 2; i < nums.size(); i++)
        {
            if (prev_total < prev + nums[i])
                total = prev + nums[i];
            else
                total = prev_total;
            prev = prev_total;
            prev_total = total;
        }
        return (total);
    }
};

