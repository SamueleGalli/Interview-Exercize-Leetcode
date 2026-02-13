/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.



Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3:

Input: s = ")("
Output: [""]



Constraints:

    * 1 <= s.length <= 25
    * s consists of lowercase English letters and parentheses '(' and ')'.
    * There will be at most 20 parentheses in s.


*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool valid(string &s)
    {
        int open = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
            {
                if (open > 0)
                    open--;
                else
                    return (false);
            }
        }
        if (open != 0)
            return (false);
        return (true);
    }

    bool find_equal(vector<string> &result, string &s)
    {
        bool same = false;
        for (size_t i = 0; i < result.size(); i++)
        {
            size_t j = 0;
            while (j < result[i].size() && j < s.size())
            {
                if (result[i][j] != s[j])
                    break;
                j++;
            }
            if (j == result[i].size())
                same = true;
        }
        return (same);
    }

    int min_level;
    void generate_par(string &s, vector<string> &result, size_t i = 0, int level = 0)
    {
        if (i > s.size() - 1 || (min_level != -1 && level > min_level))
            return;
        string copy = s;
        while (i < copy.size() && copy[i] != '(' && copy[i] != ')')
            i++;
        if (copy[i] == '(' || copy[i] == ')')
            copy.erase(copy.begin() + i);
        if (!find_equal(result, copy) && valid(copy))
        {
            if (min_level == -1)
                min_level = level;
            result.push_back(copy);
        }
        generate_par(s, result, i + 1, level);
        generate_par(copy, result, i, level + 1);
    }

    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> result;
        min_level = -1;
        if (valid(s))
            result.push_back(s);
        else
            generate_par(s, result);
        return (result);
    }
};

void print_possiblity(vector<string> result)
{
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "result[" << i << "] = " << result[i] << endl;
    }
    cout << "fine stampa\n\n\n\n";
}

int main()
{
    Solution s;
    vector<string> result;
    string Par;

    Par = "(j))(";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "()())()";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "(a)())()";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = ")(";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = ")))(((((";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "n";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "))";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "x(";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "()";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "s)))c";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "s)))c)))i)))a)))o";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = ")()(";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);

    Par = "((()";
    result = s.removeInvalidParentheses(Par);
    print_possiblity(result);
}