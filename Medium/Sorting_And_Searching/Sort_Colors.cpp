/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

 

Constraints:

    * n == nums.length
    * 1 <= n <= 300
    * nums[i] is either 0, 1, or 2.

 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/
#include <vector>

class Solution
{
private:
    void swap_current(std::vector<int> &nums, size_t i, int &type)
    {
        size_t j = i;
        int temp = nums[i];
        while (count_type(type,nums,i) == 0)
            type++;
        while (j < nums.size())
        {
            if (nums[j] == type)
                break;
            j++;
        }
        if (j == nums.size())
            return;
        nums[i] = nums[j];
        nums[j] = temp;
    }
    int count_type(int type, std::vector<int> nums, size_t i)
    {
        int count = 0;
        while (i < nums.size())
        {
            if (nums[i] == type)
                count++;
            i++;
        }
        return (count);
    }

public:
    void sortColors(std::vector<int> &nums)
    {
        int type = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (type != nums[i])
                swap_current(nums,i, type);
        }
    }
};