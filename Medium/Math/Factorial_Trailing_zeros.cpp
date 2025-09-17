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