#include <vector>

using namespace std;

class Solution
{
private:
    void life_death(vector<vector<int>> &board, size_t i, size_t j)
    {
        int life = 0;
        if (j + 1 < board[i].size())
        {
            if (board[i][j + 1] == 1 || board[i][j + 1] == 2)
                life++;
        }
        if (j + 1 < board[i].size() && i != 0)
        {
            if (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2)
                life++;
        }
        if (j + 1 < board[i].size() && i + 1 < board.size())
        {
            if (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 2)
                life++;
        }
        if (i != 0)
        {
            if (board[i - 1][j] == 1 || board[i - 1][j] == 2)
                life++;
        }
        if (i + 1 < board.size())
        {
            if (board[i + 1][j] == 1 || board[i + 1][j] == 2)
                life++;
        }
        if (j != 0)
        {
            if (board[i][j - 1] == 1 || board[i][j - 1] == 2)
                life++;
        }
        if (j != 0 && i != 0)
        {
            if (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2)
                life++;
        }
        if (j != 0 && i + 1 < board.size())
        {
            if (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2)
                life++;
        }
        if ((life < 2 || life > 3) && board[i][j] == 1)
            board[i][j] = 2;
        if (life == 3 && board[i][j] == 0)
            board[i][j] = 3;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                life_death(board, i, j);
            }
        }
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};