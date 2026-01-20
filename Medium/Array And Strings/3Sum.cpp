/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

 

Constraints:

    * 3 <= nums.length <= 3000
    * -10^5 <= nums[i] <= 10^5


*/
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
                    end--;
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