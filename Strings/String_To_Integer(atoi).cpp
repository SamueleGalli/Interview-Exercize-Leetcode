#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
#include <limits>

class Solution
{
public:
    int myAtoi(std::string s)
    {
        int sign = +1;
        if (s.size() == 0)
            return (0);
        size_t i = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;
        while (s[i] == '0')
        {
            i++;
        }
        bool max_reached = false;
        long num = 0;
        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - 48);
                if (num > std::numeric_limits<int>::max())
                {
                    max_reached = true;
                    break;
                }
            }
            else
                break;
            i++;
        }
        int result = static_cast<int>(num);
        if (max_reached)
        {
            if (sign < 0)
                result = std::numeric_limits<int>::min();
            else
                result = std::numeric_limits<int>::max();
            return (result);
        }
        if (sign < 0)
            result = -result;
        return (result);
    }
};