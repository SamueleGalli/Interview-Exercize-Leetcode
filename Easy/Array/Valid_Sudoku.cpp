#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

class Solution
{
public:
    bool raw_col_valid(std::vector<std::vector<char>> &board, size_t i, size_t j, char value)
    {
        size_t temp_j = j;
        size_t temp_i = i;
        j++;
        if (j != temp_j)
        {
            while (j < board[i].size())
            {
                if (board[i][j] && board[i][j] == value)
                    return (false);
                j++;
            }
        }
        j = temp_j;
        if (j != 0)
            j--;
        if (j != temp_j)
        {
            while (j > 0 || j == 0)
            {
                if (board[i][j] == value)
                    return (false);
                if (j == 0)
                    break;
                j--;
            }
        }
        j = temp_j;
        i++;
        if (i != temp_i)
        {
            while (i < board.size())
            {
                if (board[i][j] == value)
                    return (false);
                i++;
            }
        }
        i = temp_i;
        if (i != 0)
            i--;
        if (i != temp_i)
        {
            while (i > 0 || i == 0)
            {
                if (board[i][j] == value)
                    return (false);
                if (i == 0)
                    break;
                i--;
            }
        }
        return (true);
    }

    bool square_valid(std::vector<std::vector<char>> &board, size_t i, size_t j, char value)
    {
        size_t temp_i = i;
        size_t temp_j = j;
        if (j > 0 && j <= 2)
            j = 0;
        else if (j > 3 && j <= 5)
            j = 3;
        else if (j > 6 && j <= 8)
            j = 6;
        if (i > 0 && i <= 2)
            i = 0;
        else if (i > 3 && i <= 5)
            i = 3;
        else if (i > 6 && i <= 8)
            i = 6;
        for (int col = 3; col != 0; col--)
        {
            for (int raw = 3; raw != 0; raw--)
            {
                if (i != temp_i || j != temp_j)
                {
                    if (value == board[i][j])
                        return (false);
                }
                j++;
            }
            i++;
            j = j - 3;
        }
        return (true);
    }
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] !=  '.')
                {
                    if (raw_col_valid(board, i, j, board[i][j]) != true || square_valid(board, i, j, board[i][j]) != true)
                        return (false);
                }
            }
        }
        return (true);
    }
};
