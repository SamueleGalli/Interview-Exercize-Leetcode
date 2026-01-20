/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = "2"
Output: ["a","b","c"]

 

Constraints:

    * 1 <= digits.length <= 4
    * digits[i] is a digit in the range ['2', '9'].


*/

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