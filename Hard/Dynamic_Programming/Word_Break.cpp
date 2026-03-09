/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false



Constraints:

    * 1 <= s.length <= 300
    * 1 <= wordDict.length <= 1000
    * 1 <= wordDict[i].length <= 20
    * s and wordDict[i] consist of only lowercase English letters.
    * All the strings of wordDict are unique.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    size_t valid_word(string &s, vector<string> &dict, size_t i = 0, size_t word = 0, size_t words = 0)
    {
        if (words == dict.size())
            return (0);

        if (word == dict[words].size())
            return (i);

        if (s[i] == dict[words][word])
            i = valid_word(s, dict, i + 1, word + 1, words);
        else
            i = valid_word(s, dict, i, word, words + 1);
        return (i);
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // vector<vector<string>> memo;
        size_t i = 0;
        while (i < s.size())
        {
            string my_word = s.substr(i);
            size_t check = valid_word(my_word, wordDict);
            if (check == 0)
                return (false);
            i += check;
        }
        return (true);
    }
};

int main()
{
    Solution s;
    bool result;
    string word;
    vector<string> wordDict;

    word = "leetcode";
    wordDict = {"leet", "code"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;

    word = "applepenapple";
    wordDict = {"apple", "pen"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;

    word = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;

    word = "apple";
    wordDict = {"app", "le", "pie"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;

    word = "aaaa";
    wordDict = {"a", "aa"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;

    word = "aaaaaaa";
    wordDict = {"a", "aa", "aa"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;

    word = "aaaaaaaaaaaaaaaaaaaa";
    wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;

    word = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    wordDict = {
        "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa",
        "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaaa",
        "aaaaaaaaaaaa", "aaaaaaaaaaaaa", "aaaaaaaaaaaaaa",
        "aaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaa",
        "aaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;

    word = "cars";
    wordDict = {"car", "ca", "rs"};
    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;
    //deve esplorare tutte le strade e fare true
}