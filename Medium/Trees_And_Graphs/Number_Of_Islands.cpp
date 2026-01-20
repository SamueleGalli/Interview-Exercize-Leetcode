/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

 

Constraints:

    * m == grid.length
    * n == grid[i].length
    * 1 <= m, n <= 300
    * grid[i][j] is '0' or '1'.


*/

#include <vector>

class Solution
{
private:
    void cornering_island(std::vector<std::vector<char>> &grid, size_t i, size_t j)
    {
        if (i >= grid.size() || j >= grid[i].size() || grid[i][j] == '2' || grid[i][j] == '0')
            return;
        grid[i][j] = '2';
        cornering_island(grid, i, j + 1);
        cornering_island(grid, i + 1, j);
        if (j > 0)
            cornering_island(grid, i, j - 1);
        if (i > 0)
            cornering_island(grid, i - 1, j);
    }

public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int islands = 0;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    cornering_island(grid, i, j);
                }
            }
        }
        return (islands);
    }
};