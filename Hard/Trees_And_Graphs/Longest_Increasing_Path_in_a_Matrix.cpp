/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).



Example 1:

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:

Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:

Input: matrix = [[1]]
Output: 1



Constraints:

    * m == matrix.length
    * n == matrix[i].length
    * 1 <= m, n <= 200
    * 0 <= matrix[i][j] <= 2^31 - 1


*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int flood_fill_max(size_t i, size_t j, vector<vector<int>> &matrix, vector<vector<int>> &memo)
    {
        int total = 0;
        if (memo[i][j] != 0)
            return (memo[i][j]);
        if (i + 1 < matrix.size() && matrix[i][j] < matrix[i + 1][j])
            total = max(flood_fill_max(i + 1, j, matrix, memo), total);
        if (static_cast<int>(i - 1) >= 0 && matrix[i][j] < matrix[i - 1][j])
            total = max(flood_fill_max(i - 1, j, matrix, memo), total);
        if (j + 1 < matrix[i].size() && matrix[i][j] < matrix[i][j + 1])
            total = max(flood_fill_max(i, j + 1, matrix, memo), total);
        if (static_cast<int>(j - 1) >= 0 && matrix[i][j] < matrix[i][j - 1])
            total = max(flood_fill_max(i, j - 1, matrix, memo), total);
        memo[i][j] = ++total;
        return (total);
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return (0);
        int result = 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                result = max(flood_fill_max(i, j, matrix, memo), result);
            }
        }
        return (result);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;
    int result = 0;

    matrix =
        {{1}};
    result = s.longestIncreasingPath(matrix);
    cout << "the longest path is = " << result << endl;

    matrix =
        {{9, 9, 4},
         {6, 6, 8},
         {2, 1, 1}};
    result = s.longestIncreasingPath(matrix);
    cout << "the longest path is = " << result << endl;

    matrix =
        {{3, 4, 5},
         {3, 2, 6},
         {2, 2, 1}};
    result = s.longestIncreasingPath(matrix);
    cout << "the longest path is = " << result << endl;

    matrix =
        {{7, 7, 5},
         {2, 4, 6},
         {8, 2, 0}};
    result = s.longestIncreasingPath(matrix);
    cout << "the longest path is = " << result << endl;

    matrix =
        {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
         {19, 18, 17, 16, 15, 14, 13, 12, 11, 10},
         {20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
         {39, 38, 37, 36, 35, 34, 33, 32, 31, 30},
         {40, 41, 42, 43, 44, 45, 46, 47, 48, 49},
         {59, 58, 57, 56, 55, 54, 53, 52, 51, 50},
         {60, 61, 62, 63, 64, 65, 66, 67, 68, 69},
         {79, 78, 77, 76, 75, 74, 73, 72, 71, 70},
         {80, 81, 82, 83, 84, 85, 86, 87, 88, 89},
         {99, 98, 97, 96, 95, 94, 93, 92, 91, 90},
         {100, 101, 102, 103, 104, 105, 106, 107, 108, 109},
         {119, 118, 117, 116, 115, 114, 113, 112, 111, 110},
         {120, 121, 122, 123, 124, 125, 126, 127, 128, 129},
         {139, 138, 137, 136, 135, 134, 133, 132, 131, 130},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    result = s.longestIncreasingPath(matrix);
    cout << "the longest path is = " << result << endl;
}