/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

    * '.' Matches any single character.​​​​
    * '*' Matches zero or more of the preceding element.

Return a boolean indicating whether the matching covers the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".



Constraints:

    * 1 <= s.length <= 20
    * 1 <= p.length <= 20
    * s contains only lowercase English letters.
    * p contains only lowercase English letters, '.', and '*'.
    * It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    size_t exclude_equal(string p, size_t j)
    {
        while (j < p.size() && p[j] == '*')
            j++;
        return (j);
    }
    void matched(string s, string p, map<pair<size_t, size_t>, bool> &memo, bool &valid, size_t i = 0, size_t j = 0)
    {
        if (i == s.size() && j == p.size())
            valid = true;
        if (valid == true || memo.count(make_pair(i, j)))
            return;
        if (j + 1 < p.size() && p[j + 1] == '*')
            j++;
        if (i < s.size() && j < p.size())
        {
            if (p[j] == '.' || s[i] == p[j])
                matched(s, p, memo, valid, i + 1, j + 1);
        }
        if (p[j] == '*')
        {
            matched(s, p, memo, valid, i, j + 1);
            if (i < s.size() && (s[i] == p[j - 1] || p[j - 1] == '.'))
                matched(s, p, memo, valid, i + 1, j);
        }
        memo[make_pair(i, j)] = valid;
    }
    bool isMatch(string s, string p)
    {
        bool valid = false;
        map<pair<size_t, size_t>, bool> memo;
        matched(s, p, memo, valid);
        return (valid);
    }
};

int main()
{
    Solution s;
    string word;
    string pattern;
    bool result;

    word = "aa";
    pattern = "a";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "aa";
    pattern = "a*";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "ab";
    pattern = ".*";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";


    word = "aab";
    pattern = "c*a*b";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";
}