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
    * 1 <= words.length <= 3 * 10^4
    * 1 <= words[i].length <= 10
    * words[i] consists of lowercase English letters.
    * All the strings of words are unique.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    Solution *root[26]; // Trie per le 26 lettere minuscole
    bool is_word = false;

public:
    Solution()
    {
        for (size_t i = 0; i < 26; i++)
        {
            root[i] = nullptr;
        }
    }

    void insert(string word)
    {
        Solution *current = this;
        int index;

        for (char c : word)
        {
            index = c - 'a';
            if (!current->root[index])
                current->root[index] = new Solution();
            current = current->root[index];
        }
        current->is_word = true;
    }

    void find_prashe(vector<vector<char>> &board, int i, int j, Solution *find, string &single, vector<string> &result)
    {
        if (i < 0 || j < 0 || i >= static_cast<int>(board.size()) ||
            j >= static_cast<int>(board[i].size()) || board[i][j] == 'X')
            return;

        char c = board[i][j];
        if (find->root[c - 'a'])
        {
            single.push_back(board[i][j]);
            board[i][j] = 'X';
            find = find->root[c - 'a'];
        }
        else
            return;
        if (find->is_word)
        {
            result.push_back(single);
            find->is_word = false;
        }
        find_prashe(board, i - 1, j, find, single, result);
        find_prashe(board, i + 1, j, find, single, result);
        find_prashe(board, i, j + 1, find, single, result);
        find_prashe(board, i, j - 1, find, single, result);
        single.pop_back();
        board[i][j] = c;
        return;
    }
    void delete_Solution(Solution *&find)
    {
        if (!find)
            return;

        for (size_t i = 0; i < 26; i++)
        {
            if (find->root[i])
                delete_Solution(find->root[i]);
        }
        delete find;
        find = nullptr;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Solution *find = new Solution();
        string single;
        vector<string> result;

        for (string word : words)
            find->insert(word);

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                find_prashe(board, static_cast<int>(i), static_cast<int>(j), find, single, result);
            }
        }
        delete_Solution(find);
        find = nullptr;
        return (result);
    }
};

void word_finded(vector<string> result)
{
    cout << "\n------------------------------------------------\n";
    if (result.empty())
        cout << "e vuoto\n";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "result[" << i << "] = " << result[i] << endl;
    }
    cout << "\n------------------------------------------------\n";
}

int main()
{
    Solution s;
    vector<vector<char>> board;
    vector<string> words;
    vector<string> result;

    words = {"oath", "pea", "eat", "rain"};
    board = {{'o', 'a', 'a', 'n'},
             {'e', 't', 'a', 'e'},
             {'i', 'h', 'k', 'r'},
             {'i', 'f', 'l', 'v'}};
    result = s.findWords(board, words);
    word_finded(result);

    words = {"abcb"};
    board = {{'a', 'b'}, {'c', 'd'}};
    result = s.findWords(board, words);
    word_finded(result);

    words = {"aaa"};
    board = {{'a', 'a'}};
    result = s.findWords(board, words);
    word_finded(result);

    words = {"oath", "pea", "eat", "rain", "hklf", "hf"};
    board = {{'o', 'a', 'a', 'n'},
             {'e', 't', 'a', 'e'},
             {'i', 'h', 'k', 'r'},
             {'i', 'f', 'l', 'v'}};
    result = s.findWords(board, words);
    word_finded(result);

    words = {"ab", "cb", "ad", "bd", "ac", "ca", "da", "bc", "db", "adcb", "dabc", "abb", "acb"};
    board = {{'a', 'b'},
             {'c', 'd'}};
    result = s.findWords(board, words);
    word_finded(result);

    words = {"eaafgdcba", "eaabcdgfa"};
    board = {{'a', 'b', 'c'},
             {'a', 'e', 'd'},
             {'a', 'f', 'g'}};
    result = s.findWords(board, words);
    word_finded(result);
}