#include <stack>

class MinStack
{
private:
    std::stack<int> stack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        stack.push(val);
    }

    void pop()
    {
        if (!stack.empty())
            stack.pop();
    }

    int top()
    {
        if (stack.empty())
            return (0);
        return(stack.top());
    }

    int getMin()
    {
        if (stack.empty())
            return (0);
        std::stack<int> copy = stack;
        int min = stack.top();
        while (!copy.empty())
        {
            if (copy.top() < min)
                min = copy.top();
            copy.pop();
        }
        return(min);
    }
};