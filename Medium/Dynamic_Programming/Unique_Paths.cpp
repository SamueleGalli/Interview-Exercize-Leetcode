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