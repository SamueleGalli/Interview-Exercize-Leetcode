#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        size_t size = digits.size() - 1;
        if (digits[size] < 9)
            digits[size] = digits[size] + 1;
        else
        {
            for (size_t i = digits.size() - 1; i > 0; i--)
            {
                if (digits[i] == 9)
                    digits[i] = 0;
                else
                {
                    digits[i] = digits[i] + 1;
                    return(digits);
                }
            }
            if (digits[0] == 9)
            {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            }
            else
                digits[0] = digits[0] + 1;
        }
        return(digits);
    }
};