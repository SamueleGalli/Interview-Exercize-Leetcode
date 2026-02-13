/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    * '?' Matches any single character.
    * '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.



Constraints:

    * 0 <= s.length, p.length <= 2000
    * s contains only lowercase English letters.
    * p contains only lowercase English letters, '?' or '*'.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    size_t skip_wildcard(string p, size_t j)
    {
        while (j + 1 < p.size() && p[j + 1] == '*')
            j++;
        return (j);
    }

    void matching(string &s, string &p, bool &valid, map<pair<size_t, size_t>, bool> &memo, size_t i = 0, size_t j = 0)
    {
        if (i == s.size() && j == p.size())
            valid = true;
        if (valid == true || j == p.size() || memo.count(make_pair(i, j)))
            return;

        if (j < p.size() && p[j] == '*')
        {
            j = skip_wildcard(p, j);
            matching(s, p, valid, memo, i, j + 1);
            if (i < s.size())
                matching(s, p, valid, memo, i + 1, j);
            memo[make_pair(i, j)] = valid;
        }
        else if (i < s.size() && j < p.size() &&
                 (s[i] == p[j] || p[j] == '?'))
            matching(s, p, valid, memo, i + 1, j + 1);
    }

    bool isMatch(string s, string p)
    {
        map<pair<size_t, size_t>, bool> memo;
        bool valid = false;
        matching(s, p, valid, memo);
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

    word = "cb";
    pattern = "?a";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "cb";
    pattern = "?b";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "aa";
    pattern = "*";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "";
    pattern = "****";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "qnuibc";
    pattern = "qn*??*c";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "qnuibqbqqmwioniqwbuqwbewqneiniubyu12";
    pattern = "qnu*bq?*ni*yu*";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "adceb";
    pattern = "*a*b";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "abcabczzzde";
    pattern = "*abc???de*";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";

    word = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
    pattern = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
    result = s.isMatch(word, pattern);
    cout << boolalpha << "il risultato e = " << result << "\n\n";
}