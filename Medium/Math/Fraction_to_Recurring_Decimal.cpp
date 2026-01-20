/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 10^4 for all the given inputs.

Note that if the fraction can be represented as a finite length string, you must return it.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:

Input: numerator = 2, denominator = 1
Output: "2"

Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"

 

Constraints:

    * -2^31 <= numerator, denominator <= 2^31 - 1
    * denominator != 0


*/
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        long int n = numerator;
        long int d = denominator;
        map<long,long> razional;
        long start;
        string str_result;

        if (d == 0)
            return ("Error:impossible division by zero");
        if (n == 0)
            return ("0");
        if ((d < 0) != (n < 0))
            str_result = '-';
        if (n % d == 0)
            return (str_result = to_string(n / d));

        n = abs(n);
        d = abs(d);
        
        str_result += to_string(n / d);
        str_result += '.';
        n %= d;
        while (n != 0)
        {
            if (razional.count(n))
            {
                start = razional[n];
                str_result.insert(start, 1, '(');
                str_result += ')';
                
                break;
            }
            razional[n] = str_result.size();

            n = n * 10;
            str_result = str_result + to_string(n / d);
            n = n % d;
        }
        return (str_result);
    }
};