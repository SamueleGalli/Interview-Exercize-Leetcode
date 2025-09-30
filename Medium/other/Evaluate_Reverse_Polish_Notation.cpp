#include <vector>
#include <stack>

using namespace std;

class Solution
{
private:
    int calculated(int n1, int n2, string sign)
    {
        if (sign == "-")
        {
            return (n2 - n1);
        }
        if (sign == "+")
        {
            return (n2 + n1);
        }
        if (sign == "/")
        {
            return (n2 / n1);
        }
        if (sign == "*")
        {
            return (n2 * n1);
        }
        return (0);
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> result;
        int n1 = 0;
        int n2 = 0;
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] != "+" && tokens[i] != "*" &&
                tokens[i] != "/" && tokens[i] != "-")
                result.push(stoi(tokens[i]));
            else
            {
                n1 = result.top();
                result.pop();
                n2 = result.top();
                result.pop();
                result.push(calculated(n1, n2, tokens[i]));
            }
        }
        return (result.top());
    }
};