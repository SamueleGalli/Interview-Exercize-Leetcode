#include "vector"
#include "iostream"
#include "algorithm"
#include "iterator"
#include "unordered_set"
class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> dup;
        for (size_t i = 0;i < nums.size(); i++)
        {
            int value = nums[i];
            if (dup.count(value))
                return(true);
            else
                dup.insert(value);
        }
        return(false);
    }
};