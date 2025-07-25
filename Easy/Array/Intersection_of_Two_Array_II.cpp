#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> vector_res;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        size_t i = 0;
        size_t j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                vector_res.push_back(nums1[i]);
                i++;
                j++;
            }
            else
            {
                if (nums1[i] < nums2[j])
                   i++;
                else
                    j++;    
            }
        }
        return(vector_res);
    }
};
