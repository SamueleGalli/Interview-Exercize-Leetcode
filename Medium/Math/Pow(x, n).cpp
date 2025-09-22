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