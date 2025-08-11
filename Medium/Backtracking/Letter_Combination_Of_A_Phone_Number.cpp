#include <vector>
#include <string>

class Solution
{
private:
    void backtracking(std::vector<std::string> &solution, std::vector<std::string> letters,
    size_t i, const std::string digits, std::string &string_part)
    {
        if (i == digits.size())
        {
            solution.push_back(string_part);
            return;
        }
        int num = digits[i] - '0';
        for (size_t j = 0; j < letters[num].size(); j++)
        {
            string_part.push_back(letters[num][j]);
            backtracking(solution, letters, i + 1, digits, string_part);
            string_part.pop_back();
        }
        return;
    }

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::string parzial;
        std::vector<std::string> solution;
        if (digits.empty())
            return (solution);
        std::vector<std::string> letters = {"", "", "abc", "def",
        "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(solution, letters, 0, digits, parzial);
        return solution;
    }
};