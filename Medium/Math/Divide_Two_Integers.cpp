#include <limits>
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