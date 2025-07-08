#include <vector>
class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int max = nums[0];
        int current_num = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (current_num < 0)
                current_num = nums[i];
            else
                current_num = current_num + nums[i];
            if (current_num > max)
                max = current_num;
        }
        return (max);
    }
};
