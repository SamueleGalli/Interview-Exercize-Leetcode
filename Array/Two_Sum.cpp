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