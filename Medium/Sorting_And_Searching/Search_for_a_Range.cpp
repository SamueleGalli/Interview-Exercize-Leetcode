#include <vector>

class Solution
{
    private:
    void    create_range(size_t i, std::vector<int> &range, int target, std::vector<int> nums)
    {
        while (i < nums.size())
        {
            if (nums[i] != target)
            {
                range.push_back(i - 1);
                return;
            }
            i++;
        }
        range.push_back(i - 1);
        return;
    }
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        std::vector<int> range;
        for (size_t i = 0;i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                range.push_back(i);
                create_range(i, range, target, nums);
                return (range);
            }
        }
        range.push_back(-1);
        range.push_back(-1);
        return (range);
    }
};