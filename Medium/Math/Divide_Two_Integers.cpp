/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

 

Constraints:

    * -2^31 <= dividend, divisor <= 2^31 - 1
    * divisor != 0


*/
#include <limits>
#include <math.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (numeric_limits<int>::min() == dividend && divisor == -1)
            return (numeric_limits<int>::max());
        long int result = 0;
        bool sign = true;
        if (static_cast<long int>(dividend) < 0 !=
        static_cast<long int>(divisor) < 0)
        sign = false;
        long int d1 = abs((long int)dividend);
        long int d2 = abs((long int)divisor);
        for (int i = 31;i >= 0 && d1 > 0; --i)
        {
            if ((d2 << i) <= d1)
            {
                d1 = d1 - (d2 << i);
                result = result | (1LL << i);
            }
        }
        if (sign == false)
            return (-result);
        return (result);
    }
};