#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int zeros = 0;
        for (auto it = nums.begin(); it != nums.end();)
        {
            if (*it == 0)
            {
                zeros++;
                it = nums.erase(it);
            }
            else
                it++;
        }
        while (zeros > 0)
        {
            nums.push_back(0);
            zeros--;
        }
    }
};