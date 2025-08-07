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