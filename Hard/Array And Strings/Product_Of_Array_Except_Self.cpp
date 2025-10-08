#include <vector>

using namespace std;

class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>answer = {1};
        int suffix = 1;
        int i = 0;
        while ((size_t)i < nums.size() - 1)
        {
            answer.push_back(nums[i] * answer.back());
            i++;
        };
        while (i >= 0)
        {
            answer[i] = suffix * answer[i];
            suffix = nums[i] * suffix;
            i--;
        }
        return (answer);
    }
};