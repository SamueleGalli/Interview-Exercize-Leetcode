#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::vector<int> result;
        int max = nums.size();
        for (int i = 0; i < max; i++)
        {
            if (std::find(result.begin(), result.end(), nums[i]) == result.end())
                result.push_back(nums[i]);   
        }
        nums = result;
        return (result.size());
    }
};