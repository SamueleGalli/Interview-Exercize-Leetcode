/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

 

Constraints:

    * -100.0 < x < 100.0
    * -2^31 <= n <= 2^31-1
    * n is an integer.
    * Either x is not zero or n > 0.
    * -10^4 <= xn <= 10^4


*/
#include <iomanip>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1.00000 || n == 0)
            return (1.00000);
        long int positive_n = n;
        int division = 0;
        double result = 1;
        double exp = x;
        if (n < 0)
        {
            division = 1;
            positive_n = -positive_n;
        }
        while (positive_n > 0) 
        {
            if (positive_n % 2 == 1)
                result = result * exp;
            exp *= exp;
            positive_n /= 2;
        }
        if (division == 1)
            result = 1 / result;
        return (result);

    }
};