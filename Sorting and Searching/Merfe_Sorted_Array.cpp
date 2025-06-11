#include <algorithm>
#include <vector>
class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        nums1.erase(nums1.begin() + m, nums1.end());
        size_t tot = n + m;
        for (size_t i = 0; i < tot; i++)
        {
            if (i < nums2.size())
            {
                size_t j = i;
                size_t i2 = 0;
                while (i2 < nums1.size())
                {
                    if (nums2[j] <= nums1[i2])
                    {  
                        nums1.insert(nums1.begin() + i2, nums2[j]);
                        break;
                    }
                    i2++;
                }
                if (i2 == nums1.size())
                    nums1.insert(nums1.begin() + i2, nums2[j]);
            }
            else
                break;
        }
    }
};