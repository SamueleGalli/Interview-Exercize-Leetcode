/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

 

Constraints:

    * 0 <= nums.length <= 10^5
    * -10^9 <= nums[i] <= 10^9
    * nums is a non-decreasing array.
    * -10^9 <= target <= 10^9


*/

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