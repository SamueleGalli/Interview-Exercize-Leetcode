/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

 

Constraints:

    * -2^31 <= x <= 2^31 - 1


*/

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