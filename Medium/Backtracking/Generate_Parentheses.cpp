#include <vector>
#include <string>

class Solution
{
    void loop_parhentesis(std::vector<std::string> &Solution, int n, int open, std::string temp_p, int closed)
    {
        if (open == n && closed == n)
        {
            Solution.push_back(temp_p);
            return;
        }
        if (open < n)
        {
            temp_p.push_back('(');
            loop_parhentesis(Solution, n, open + 1, temp_p, closed);
            temp_p.pop_back();
        }
        if (closed < open)
        {    
            temp_p.push_back(')');
            loop_parhentesis(Solution, n, open, temp_p, closed + 1);
            temp_p.pop_back();
        }
        return;
    }
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> solution;
        std::string temp_p;
        int open = 0;
        int closed = 0;
        loop_parhentesis(solution, n, open, temp_p, closed);
        return (solution);
    }
};