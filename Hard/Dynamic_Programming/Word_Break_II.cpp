/*
        Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []



Constraints:

    * 1 <= s.length <= 20
    * 1 <= wordDict.length <= 1000
    * 1 <= wordDict[i].length <= 10
    * s and wordDict[i] consist of only lowercase English letters.
    * All the strings of wordDict are unique.
    * Input is generated in a way that the length of the answer doesn't exceed 105.
*/

using namespace std;

#include <vector>
#include <iostream>

class Solution
{
public:
    vector<string> take_words(string s, vector<string> &dict, vector<vector<string>> &memo, size_t i_s = 0)
    {
        vector<string> comb;
        vector<string> taken;
        string final;

        if (i_s == s.size())
            return (vector<string>{""});

        if (!memo[i_s].empty())
            return (memo[i_s]);

        for (string words : dict)
        {
            if (words == s.substr(i_s, words.size()))
            {
                taken = take_words(s, dict, memo, i_s + words.size());
                for (string take_me : taken)
                {
                    if (!take_me.empty())
                        final = words + " " + take_me;
                    else
                        final = words;
                    comb.push_back(final);
                }
            }
        }
        memo[i_s] = comb;
        return (comb);
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<vector<string>> memo(s.size());
        return (take_words(s, wordDict, memo));
    }
};

void stamp_result(vector<string> &result)
{
    if (result.empty())
        cout << "\n\nnothing in there\n\n";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "result[" << i << "] = " << result[i] << endl;
    }
    result.clear();
}

int main()
{
    Solution s;
    vector<string> result;
    string word;
    vector<string> wordDict;

    word = "catsanddog";
    wordDict = {"cat", "cats", "and", "sand", "dog"};
    result = s.wordBreak(word, wordDict);
    stamp_result(result);

    word = "pineapplepenapple";
    wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    result = s.wordBreak(word, wordDict);
    stamp_result(result);

    word = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    result = s.wordBreak(word, wordDict);
    stamp_result(result);
}