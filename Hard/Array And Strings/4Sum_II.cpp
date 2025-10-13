#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> summed;
        int totale = 0;
        int num_totale = 0;
        for (size_t i = 0;i < nums1.size();i++)
        {
            for (size_t j = 0;j < nums2.size();j++)
            {
                totale = nums2[j] + nums1[i];
                summed[totale]++;
            }
        }
        int target = 0;
        for (size_t i = 0;i < nums3.size();i++)
        {
            for (size_t j = 0;j < nums4.size();j++)
            {
                totale = nums4[j] + nums3[i];
                target = -totale;
                num_totale += summed[target];
            }
        }
        return (num_totale);
    }
};