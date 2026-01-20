/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

 

Constraints:

    * m == matrix.length
    * n == matrix[i].length
    * 1 <= m, n <= 10
    * -100 <= matrix[i][j] <= 100


*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> spiral;
        size_t i = 0;
        int loop = 0;
        size_t j = 0;
        for (;i < matrix.size();i++)
        {
            loop++;
            for (;j < matrix[i].size() && matrix[i][j] != 1000;j++)
            {
                loop = 0;
                spiral.push_back(matrix[i][j]);
                matrix[i][j] = 1000;
            }
            j--;
            i++;
            while (i < matrix.size() && matrix[i][j] != 1000)
            {
                loop = 0;
                spiral.push_back(matrix[i][j]);
                matrix[i][j] = 1000;
                i++;
            }
            i--;
            j--;
            while ((int)j >= 0 && matrix[i][j] != 1000)
            {
                loop = 0;
                spiral.push_back(matrix[i][j]);
                matrix[i][j] = 1000;
                j--;
            }
            j++;
            i--;
            while ((int)i > 0 && matrix[i][j] != 1000)
            {
                loop = 0;
                spiral.push_back(matrix[i][j]);
                matrix[i][j] = 1000;
                i--;
            }
            if (loop == 1)
                break;
            j++;
        }
        return (spiral);
    }
};