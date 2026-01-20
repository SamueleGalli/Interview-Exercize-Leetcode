/*
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:

Input: n = 0
Output: 0

 

Constraints:

    * 0 <= n <= 10^4

 

Follow up: Could you write a solution that works in logarithmic time complexity?

*/

#include <cmath>

using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int result = 0;
        int factorial = 5;
        int power = 1;
        while (factorial <= n)
        {
            power++;
            result = result + ( n / factorial);
            factorial = pow(5,power);
        }
        return (result);
    }
};