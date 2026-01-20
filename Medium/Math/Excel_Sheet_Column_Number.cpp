/*
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

 

Example 1:

Input: columnTitle = "A"
Output: 1

Example 2:

Input: columnTitle = "AB"
Output: 28

Example 3:

Input: columnTitle = "ZY"
Output: 701

 

Constraints:

    * 1 <= columnTitle.length <= 7
    * columnTitle consists only of uppercase English letters.
    * columnTitle is in the range ["A", "FXSHRXW"].


*/

#include <vector>
#include <cmath>
#include <string>
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