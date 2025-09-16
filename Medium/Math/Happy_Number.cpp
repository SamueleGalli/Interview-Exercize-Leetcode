#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        std::vector<int> loop;
        int digit = 0;
        while (n != 0)
        {
            if (!loop.empty() && find(loop.begin(), loop.end(), n) != loop.end())
                break;
            loop.push_back(n);
            while (n > 0)
            {
                digit += pow(n % 10, 2);
                n /= 10;
            }
            if (digit == 1)
                return (true);
            n = digit;
            digit = 0;
        }
        return (false);
    }
};