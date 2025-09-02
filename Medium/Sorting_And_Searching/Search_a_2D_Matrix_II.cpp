#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        size_t row = 0;
        int  col = static_cast<int>(matrix.size() - 1);
        while (col >= 0 && row < matrix[col].size())
        {
            if (matrix[col][row] == target)
                return (true);
            if (matrix[col][row] > target)
                col--;
            else
                row++;
        }
        return (false);
    }
};
