#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);
        for (size_t i = 1; i < dp.size();i++)
        {
            for (size_t j = 0;j < i;j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = std::max(1 + dp[j], dp[i]);
            }
        }
        return (*std::max_element(dp.begin(), dp.end()));
    }
};