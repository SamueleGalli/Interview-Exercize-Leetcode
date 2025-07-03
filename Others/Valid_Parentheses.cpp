#include <stack>

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
