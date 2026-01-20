/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

    * 1 <= s.length <= 10^4
    * s consists of parentheses only '()[]{}'.


*/

#include <stack>
#include <string>

class Solution
{
    private:
        bool chack_validation(char closing, char open)
        {
            int type = 0;
            if (open == '(')
                type = 1;
            if (open == '[')
                type = 2;
            if (open == '{')
                type = 3;
            if ((type == 1 && closing == ')') ||
            (type == 2 && closing == ']') ||
            (type == 3 && closing == '}'))
                return (true);
            else
                return (false);
        }
public:
    bool isValid(std::string s)
    {
        std::stack<char> pharentesis;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
                pharentesis.push(s[i]);
            if (s[i] == ']' || s[i] == ')' || s[i] == '}')
            {
                if (pharentesis.empty())
                    return(false);
                if (chack_validation(s[i], pharentesis.top()) == true)
                    pharentesis.pop();
                else
                    return(false);
            }
        }
        if (!pharentesis.empty())
            return (false);
        return(true);
    }
};
