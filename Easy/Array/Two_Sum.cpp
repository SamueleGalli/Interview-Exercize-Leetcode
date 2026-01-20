/* 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    * 2 <= nums.length <= 10^4
    * -10^9 <= nums[i] <= 10^9
    * -10^9 <= target <= 10^9
    * Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::vector<int> sumup;
        for (size_t i = 0; i < nums.size();i++)
        {
            int first_digit = nums[i];
            for (size_t i2 = i; i2 < nums.size();i2++)
            {
                if (i != i2)
                {
                    if (first_digit + nums[i2] == target)
                    {
                        sumup.push_back(i);
                        sumup.push_back(i2);
                        return (sumup);
                    }
                }
            }
        }  
        sumup.push_back(0);
        sumup.push_back(0);
        return(nums);
    }
};