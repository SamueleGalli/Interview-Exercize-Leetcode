#include <vector>
#include <string>

class Solution
{
private:
    void search_word(size_t i, size_t j, size_t c, std::string word, std::vector<std::vector<char>> &board, bool &finded)
    {
        if (finded == true)
            return;
        if (word.size() == c)
        {
            finded = true;
            return;
        }
        if (i >= board.size() || j >= board[i].size() || word[c] != board[i][j] || board[i][j] == '0')
            return;
        char value = board[i][j];
        board[i][j] = '0';
        search_word(i + 1, j, c + 1, word, board, finded);
        if (i > 0)
            search_word(i - 1, j, c + 1, word, board, finded);
        search_word(i, j + 1, c + 1, word, board, finded);
        if (j > 0)
            search_word(i, j - 1, c + 1, word, board, finded);
        board[i][j] = value;
    }

public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        bool finded = false;
        size_t c = 0;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[c])
                    search_word(i, j, c, word, board, finded);
                if (finded == true)
                    break;
            }
        }
        return (finded);
    }
};