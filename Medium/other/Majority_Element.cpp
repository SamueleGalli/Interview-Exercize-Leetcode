#include <vector>
#include <map>
#include <iterator>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> count;
        for (size_t i = 0;i < nums.size(); i++)
        {
            count[nums[i]]++;
        }
        int max = 0;
        int c_max = 0;
        for (map<int,int>::iterator i = count.begin();i != count.end(); i++)
        {
            if (i->second > c_max)
            {
                max = i->first;
                c_max = i->second;
            }
        }
        return (max);
    }
};