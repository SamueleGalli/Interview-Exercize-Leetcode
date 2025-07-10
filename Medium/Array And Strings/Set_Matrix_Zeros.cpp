#include <vector>
#include <algorithm>

class Solution
{
private:
    void to_skip(std::vector<std::vector<size_t>> &skip, std::vector<std::vector<int>> matrix, size_t i, size_t j)
    {
        while (i < matrix.size())
        {
            while (j < matrix[i].size())
            {
                if (matrix[i][j] == 0)
                    skip.push_back({i, j});
                j++;
            }
            j = 0;
            i++;
        }
    }

    void set_zeros(std::vector<std::vector<int>> &matrix, size_t i, size_t j)
    {
        size_t i2 = i;
        size_t j2 = j;
        if (i > 0)
        {
            while (i != 0)
            {
                matrix[i][j] = 0;
                i--;
            }
            matrix[i][j] = 0;
        }
        i = i2;
        while (i < matrix.size())
        {
            matrix[i][j] = 0;
            i++;
        }
        i = i2;
        if (j > 0)
        {
            while (j != 0)
            {
                matrix[i][j] = 0;
                j--;
            }
            matrix[i][j] = 0;
        }
        j = j2;
        while (j < matrix[i].size())
        {
            matrix[i][j] = 0;
            j++;
        }
    }

public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        std::vector<std::vector<size_t>> skip;
        size_t i = 0;
        size_t j = 0;
        size_t d = 0;
        to_skip(skip, matrix, i, j);
        while (i < matrix.size())
        {
            while (j < matrix[i].size())
            {
                if (d < skip.size() && skip[d][0] == i && skip[d][1] == j)
                {
                    set_zeros(matrix, i, j);
                    d++;
                }
                j++;
            }
            i++;
            j = 0;
        }
    }
};