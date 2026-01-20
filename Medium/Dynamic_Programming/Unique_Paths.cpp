/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

 

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

 

Constraints:

    * 1 <= m, n <= 100


*/
#include <vector>

class Solution {
    private:
    void    limit_matrix(std::vector<std::vector<int>> &matrix, size_t i, size_t j)
    {
        while (j < matrix[i].size())
        {
            matrix[i][j] = 1;
            j++;
        }
        j = 0;
        while (i < matrix.size())
        {
            matrix[i][j] = 1;
            i++;
        }
    }

public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
        limit_matrix(matrix,0,0);
        int total = 1;
        for (size_t i = 1; i < matrix.size();i++)
        {
            for (size_t j = 1; j < matrix[i].size(); j++)
            {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
                total = matrix[i][j];
            }
        }
        return (total);
    }
};