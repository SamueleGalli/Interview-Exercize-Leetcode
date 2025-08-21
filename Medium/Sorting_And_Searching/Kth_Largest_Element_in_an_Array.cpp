#include <vector>
#include <algorithm>
class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        int k_pos = nums.size() - k;
        std::nth_element(nums.begin(), nums.begin() + k_pos, nums.end());
        return nums[k_pos];
    }
};