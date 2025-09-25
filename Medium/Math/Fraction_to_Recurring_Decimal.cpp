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