/*
Given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2^31, 2^31 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().



Example 1:

Input: s = "3+2*2"
Output: 7

Example 2:

Input: s = " 3/2 "
Output: 1

Example 3:

Input: s = " 3+5 / 2 "
Output: 5



Constraints:

    * 1 <= s.length <= 3 * 10^5
    * s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
    * s represents a valid expression.
    * All the integers in the expression are non-negative integers in the range [0, 2^31 - 1].
    * The answer is guaranteed to fit in a 32-bit integer.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        vector<string> vec;
        string value;
        int moltiplication = 0;
        int division = 0;
        int num1 = 0;
        int num2 = 0;
        int result = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            while (isdigit(s[i]))
                value += s[i++];
            if (s[i] == '+' || s[i] == '-')
            {
                if (moltiplication > 0 || division > 0)
                {
                    num2 = atoi(value.c_str());
                    if (moltiplication > 0)
                        vec.push_back(to_string(num1 * num2));
                    else if (division > 0)
                        vec.push_back(to_string(num1 / num2));
                    moltiplication = 0;
                    division = 0;
                }
                else
                    vec.push_back(value);
                value.clear();
                vec.push_back(string(1, s[i]));
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                if (moltiplication > 0 || division > 0)
                {
                    num2 = atoi(value.c_str());
                    if (moltiplication > 0)
                        num1 = num1 * num2;
                    else if (division > 0)
                        num1 = num1 / num2;
                    moltiplication = 0;
                    division = 0;
                }
                else
                    num1 = atoi(value.c_str());
                if (s[i] == '*')
                    moltiplication++;
                else if (s[i] == '/')
                    division++;
                value.clear();
            }
            if (s[i] == ' ')
                continue;
        }
        if (moltiplication > 0 || division > 0)
        {
            num2 = atoi(value.c_str());
            if (moltiplication > 0)
                vec.push_back(to_string(num1 * num2));
            else
                vec.push_back(to_string(num1 / num2));
            result = atoi(vec.front().c_str());
        }
        else
            vec.push_back(value);
        if (result == 0)
            result = atoi(vec[0].c_str());
        for (size_t i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i] == "+")
                result += atoi(vec[i + 1].c_str());
            if (vec[i] == "-")
                result -= atoi(vec[i + 1].c_str());
        }
        return (result);
    }
};

int main()
{
    Solution s;
    int result = s.calculate("3+2*2");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate(" 3/2 ");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate(" 3+5 / 2 ");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate("42");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate("2  +  2");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate("1+1+1");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate("1+1-1");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate("1-1+1");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate("2-3+4");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate("2*3+4");
    cout << "result of matematical expression = " << result << endl;
    result = s.calculate("2*3*4");
    cout << "result of matematical expression = " << result << endl;
}