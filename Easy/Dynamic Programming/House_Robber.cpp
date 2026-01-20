/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

 

Constraints:

    * 1 <= nums.length <= 100
    * 0 <= nums[i] <= 400

*/
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

