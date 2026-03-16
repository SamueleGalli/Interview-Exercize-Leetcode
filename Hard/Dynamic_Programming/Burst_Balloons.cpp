/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.



Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:

Input: nums = [1,5]
Output: 10



Constraints:

    * n == nums.length
    * 1 <= n <= 300
    * 0 <= nums[i] <= 100
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int max_point(vector<int> &nums, vector<vector<int>> &memo, size_t start, size_t end)
    {
        int bustered = 0;
        int total_max = 0;
        if (start > end)
            return (0);

        if (memo[start][end] != 0)
            return (memo[start][end]);

        for (size_t j = start; j <= end; j++)
        {
            bustered = nums[start - 1] * nums[j] * nums[end + 1];
            int right = max_point(nums, memo, j + 1, end);
            int left = max_point(nums, memo, start, j - 1);
            bustered += right + left;
            total_max = max(bustered, total_max);
        }
        memo[start][end] = total_max;
        return (total_max);
    }
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> memo(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        return (max_point(nums, memo, 1, nums.size() - 2));
    }
};

int main()
{
    Solution s;
    int result;
    vector<int> nums;

    nums = {3, 1, 5, 8};
    result = s.maxCoins(nums);
    cout << "result = " << result << endl;

    nums = {1, 5};
    result = s.maxCoins(nums);
    cout << "result = " << result << endl;
}