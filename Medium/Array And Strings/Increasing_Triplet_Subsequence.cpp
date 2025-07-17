#include <vector>
#include <limits>

class Solution
{
public:
    bool increasingTriplet(std::vector<int> &nums)
    {
        long long min = std::numeric_limits<long long>::max();
        long long max = min;
        for (size_t i = 0;i < nums.size();i++)
        {
            if (nums[i] <= min)
                min = nums[i];
            else if (nums[i] <= max)
                max = nums[i];
            else
                return(true);
        }
        return(false);
    }
};