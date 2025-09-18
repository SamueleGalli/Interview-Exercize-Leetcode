#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        if (columnTitle.length() > 1)
        {
            int power = columnTitle.length() - 1;
            for (size_t i = 0; i < columnTitle.size(); i++)
            {
                if (power == 0)
                {
                    result += columnTitle[i] - 64;
                    break;
                }
                result += (columnTitle[i] - 64) * pow(26, power);
                power--;
            }
        }
        else
        {
            result = columnTitle[0] - 64;
        }
        return (result);
    }
};