/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

 

Constraints:

    * 1 <= nums.length <= 10
    * -10 <= nums[i] <= 10
    * All the numbers of nums are unique.


*/

#include <vector>
#include <string>
class Solution
{
private:

    void create_subset(std::vector<int> nums, std::vector<std::vector<int>> &solution, std::vector<int> &subset, size_t i)
    {
        if (nums.size() == i)
        {
            solution.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        create_subset(nums, solution, subset, i + 1);
        subset.pop_back();
        create_subset(nums, solution, subset, i + 1);
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> solution;
        std::vector<int> subset;
        create_subset(nums, solution, subset, 0);
        return (solution);
    }
};