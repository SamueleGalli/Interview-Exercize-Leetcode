#include <iostream>
#include <limits>

class Solution
{
public:
    int reverse(int x)
    {
        long long int big_result = 0;
        while (x != 0)
        {
            big_result *= 10;
            big_result = big_result + (x % 10);
            x /= 10;
        }
        if (big_result < std::numeric_limits<int32_t>::min() || big_result > std::numeric_limits<int32_t>::max())
            return (0);
        return (static_cast<int>(big_result));
    }
};