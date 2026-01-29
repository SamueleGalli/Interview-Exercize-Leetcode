/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.



Constraints:

    * m == s.length
    * n == t.length
    * 1 <= m, n <= 10^5
    * s and t consist of uppercase and lowercase English letters.



Follow up: Could you find an algorithm that runs in O(m + n) time?

*/

using namespace std;

#include <string>
#include <iostream>
#include <map>

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string result = "";
        map<char, int> substring;
        for (char c : t)
            substring[c]++;
        size_t start = 0;
        size_t end = 0;
        size_t total_size = t.size();
        for (size_t i = 0; i < s.size(); i++)
        {
            if (end < i)
                end = i;
            if (total_size > 0 && substring.count(s[i]))
            {
                substring[s[i]]--;
                if (substring[s[i]] >= 0)
                    total_size--;
            }
            if (total_size == 0)
            {
                while (start < end && (substring.count(s[start]) == 0 || substring[s[start]] < 0))
                {
                    if (substring.count(s[start]) == 1 && substring[s[start]] < 0)
                        substring[s[start]]++;
                    start++;
                }
                if (result.empty() || end - start + 1 < result.size())
                    result = s.substr(start, end - start + 1);
                while (substring.count(s[start]) && substring[s[start]] <= 0)
                {
                    if (substring[s[start]] == 0)
                    {
                        substring[s[start]]++;
                        total_size++;
                        start++;
                        break;
                    }
                    substring[s[start]]++;
                    start++;
                }
            }
        }
        return (result);
    }
};

int main()
{
    Solution result;
    string t;
    string s;
    string resulting_string;
    s = "ADOBECODEBANC";
    t = "ABC";
    resulting_string = result.minWindow(s, t);
    cout << "\n\nthe smallest window is = " << resulting_string << endl;
    s = "a";
    t = "a";
    resulting_string = result.minWindow(s, t);
    cout << "\n\nthe smallest window is = " << resulting_string << endl;
    s = "a";
    t = "aa";
    resulting_string = result.minWindow(s, t);
    cout << "\n\nthe smallest window is = " << resulting_string << endl;
    s = "ADOBECODEBANCAB";
    t = "ABC";
    resulting_string = result.minWindow(s, t);
    cout << "\n\nthe smallest window is = " << resulting_string << endl;
    s = "ADOBECODEBANCAAB";
    t = "AABC";
    resulting_string = result.minWindow(s, t);
    cout << "\nthe smallest window is = " << resulting_string << endl;
    s = "caaec";
    t = "cae";
    resulting_string = result.minWindow(s, t);
    cout << "\nthe smallest window is = " << resulting_string << endl;
}