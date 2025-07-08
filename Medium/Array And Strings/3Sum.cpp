
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> three;
        if (nums.size() < 3)
            return (three);
        size_t start;
        size_t end;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            start = i + 1;
            end = nums.size() - 1;
            while (start < end)
            {
                int sum = nums[start] + nums[end] + nums[i];
                if (sum == 0)
                {
                    three.push_back({nums[start], nums[end], nums[i]});
                    while (start < end && nums[start] == nums[start + 1])
                        start++;
                    while (start < end && nums[end] == nums[end - 1])
                        end--;
                    start++;
                    end--;*
                }
                if (sum < 0)
                    start++;
                else if (sum > 0)
                    end--;
            }
        }
        return (three);
    }
};