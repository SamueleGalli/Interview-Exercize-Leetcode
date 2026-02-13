/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example 1:

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:

Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []



Constraints:

    * m == board.length
    * n == board[i].length
    * 1 <= m, n <= 12
    * board[i][j] is a lowercase English letter.
    * 1 <= words.length <= 3 * 104
    * 1 <= words[i].length <= 10
    * words[i] consists of lowercase English letters.
    * All the strings of words are unique.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    /*
    TODO controllo
    TODO operazioner
    TODO ricorsione
    TODO pulizia
    controllare le celle orizzontalmente e veritcalmente e verificare cosa ottengo
    */
    size_t find_prashe(const vector<vector<char>> &board, const vector<string> &words, size_t i, size_t j)
    {
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> result;
        int f;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                f = find_prashe(board, words, i, j);
                if (f != -1)
                    result.push_back(words[f]);
            }
        }
        return (result);
    }
};

void word_finded(vector<string> result)
{
    cout << "\n------------------------------------------------\n";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "result[" << i << "] = " << result[i] << endl;
    }
    cout << "\n------------------------------------------------\n"
}
int main()
{
    Solution s;
    vector<vector<char>> board;
    vector<string> words;
    vector<string> result;

    words = {"oath", "pea", "eat", "rain"};
    board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    result = s.findWords(board, words);
    word_finded(result);

    words = {"abcb"};
    board = {{'a', 'b'}, {'c', 'd'}};
    result = s.findWords(board, words);
    word_finded(result);
}