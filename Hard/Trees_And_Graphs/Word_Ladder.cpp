/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.



Constraints:

    * 1 <= beginWord.length <= 10
    * endWord.length == beginWord.length
    * 1 <= wordList.length <= 5000
    * wordList[i].length == beginWord.length
    * beginWord, endWord, and wordList[i] consist of lowercase English letters.
    * beginWord != endWord
    * All the words in wordList are unique.


*/

#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int strcmp(string str1, string str2)
    {
        int count = 0;

        for (size_t i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[i])
                count++;
        }
        return (count);
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (wordList.empty())
            return (0);

        queue<string> finded;
        int lenght = 1;
        size_t word_size;
        vector<bool> marked(wordList.size(), false);

        finded.push(beginWord);
        while (!finded.empty())
        {
            word_size = finded.size();
            for (size_t j = 0; j < word_size; j++)
            {
                for (size_t i = 0; i < wordList.size(); i++)
                {
                    if (strcmp(wordList[i], finded.front()) == 1 && !marked[i])
                    {
                        if (wordList[i] == endWord)
                            return (++lenght);
                        marked[i] = true;
                        finded.push(wordList[i]);
                    }
                }
                if (!finded.empty())
                {
                    finded.pop();
                    if (finded.empty())
                        break;
                }
            }
            lenght++;
        }
        return (0);
    }
};

int main()
{
    Solution s;
    string beginWord = "";
    string endWord = "";
    vector<string> wordList;
    int result;

    wordList = {};
    result = s.ladderLength(beginWord, endWord, wordList);
    cout << "result = " << result << endl;
    cout << "deve essere 0\n\n\n\n";

    beginWord = "hot";
    endWord = "dog";
    wordList = {"hot", "dog", "dot"};
    result = s.ladderLength(beginWord, endWord, wordList);
    cout << "result = " << result << endl;
    cout << "deve essere 3\n\n\n\n";

    wordList = {"hot", "dog"};
    result = s.ladderLength(beginWord, endWord, wordList);
    cout << "result = " << result << endl;
    cout << "deve essere 0\n\n\n\n";

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    result = s.ladderLength(beginWord, endWord, wordList);
    cout << "result = " << result << endl;
    cout << "deve essere 5\n\n\n\n";

    wordList = {"hot", "dot", "tog", "cog"};
    result = s.ladderLength(beginWord, endWord, wordList);
    cout << "result = " << result << endl;
    cout << "deve essere 0\n\n\n\n";

    wordList = {"hot", "dot", "dog", "lot", "log"};
    result = s.ladderLength(beginWord, endWord, wordList);
    cout << "result = " << result << endl;
    cout << "deve essere 0\n\n\n\n";

    beginWord = "hot";
    endWord = "dot";
    wordList = {"hot", "dot", "dog"};
    result = s.ladderLength(beginWord, endWord, wordList);
    cout << "result = " << result << endl;
    cout << "deve essere 2\n\n\n\n";

    beginWord = "put";
    wordList = {"hot", "hit", "hat", "lot", "hut", "dot"};
    result = s.ladderLength(beginWord, endWord, wordList);
    cout << "result = " << result << endl;
    cout << "deve essere 4\n\n\n\n";
}
