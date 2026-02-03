/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.



Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]



Constraints:

    * m == board.length
    * n == board[i].length
    * 1 <= m, n <= 200
    * board[i][j] is 'X' or 'O'.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void take_ragion(vector<vector<char>> &board, size_t i, size_t j, char c, char take)
    {
        if (board[i][j] == take)
            board[i][j] = c;
        else
            return;

        if (j + 1 < board[i].size())
            take_ragion(board, i, j + 1, c, take);
        if (static_cast<int>(j - 1) >= 0)
            take_ragion(board, i, j - 1, c, take);
        if (i + 1 < board.size())
            take_ragion(board, i + 1, j, c, take);
        if (static_cast<int>(i - 1) >= 0)
            take_ragion(board, i - 1, j, c, take);
    }
    void exclude_corner(vector<vector<char>> &board)
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            if (i == 0 || i == board.size() - 1)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    if (board[i][j] == 'O')
                        take_ragion(board, i, j, 'T', 'O');
                }
            }
            else
            {
                if (board[i][0] == 'O')
                    take_ragion(board, i, 0, 'T', 'O');
                if (board[i][board[i].size() - 1] == 'O')
                    take_ragion(board, i, board[i].size() - 1, 'T', 'O');
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        exclude_corner(board);
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'O')
                {
                    if (i > 0 && j != board[i].size() - 1 && i < board.size() - 1 && j > 0)
                        take_ragion(board, i, j, 'X', 'O');
                }
            }
        }
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'T')
                    take_ragion(board, i, j, 'O', 'T');
            }
        }
    }
};

void print_board(vector<vector<char>> board)
{
    cout << "stampa board catturata\n";
    for (size_t i = 0; i < board.size(); i++)
    {
        cout << "{";
        for (size_t j = 0; j < board[i].size(); j++)
        {
            cout << "\'" << board[i][j];
            if (j != board[i].size() - 1)
                cout << "\',";
        }
        cout << "}\n";
    }
}

int main()
{
    Solution s;
    vector<vector<char>> board;

    board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    s.solve(board);
    print_board(board);

    board = {{'X'}};

    s.solve(board);
    print_board(board);

    board = {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X'}};

    s.solve(board);
    print_board(board);

    board = {
        {'O', 'O'},
        {'O', 'O'}};

    s.solve(board);
    print_board(board);

    board = {
        {'X', 'X', 'X'},
        {'X', 'O', 'X'},
        {'X', 'X', 'X'}};

    s.solve(board);
    print_board(board);

    board = {
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'}};

    s.solve(board);
    print_board(board);

    board = {
        {'O', 'X', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', 'O', 'X', 'O'},
    };
    s.solve(board);
    print_board(board);
}