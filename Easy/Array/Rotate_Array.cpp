
#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    void rotate(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 0)
            return;
        k %= n; //toglie inutili ripetizioni
        //inverte l'array/inverte k numeri/rinverte da k
        std::reverse(nums.begin(), nums.end());      
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());  
    }
};