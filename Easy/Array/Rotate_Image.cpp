/* 
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

 

Constraints:

    * n == matrix.length == matrix[i].length
    * 1 <= n <= 20
    * -1000 <= matrix[i][j] <= 1000


*/

#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    void cicle(std::vector<std::vector<int>> &matrix, int i, int j, size_t size_i, size_t size_j, int count)
    {
        int top_left = matrix[i][j];
        int top_right = matrix[i + count][size_j];
        int bottom_right = matrix[size_i][size_j - count];
        int bottom_left = matrix[size_i - count][j - count];
        matrix[i + count][size_j] = top_left;
        matrix[size_i][size_j - count] = top_right;
        matrix[size_i - count][j - count] = bottom_right;
        matrix[i][j] = bottom_left;
    }

    void rotate(std::vector<std::vector<int>> &matrix)
    {
        if (matrix.size() == 1 && matrix[0].size() == 1)
            return;
        size_t j = 0;
        size_t i = 0;
        int sum = 0;
        size_t count = 0;
        size_t adder = 0;
        size_t max_i = matrix.size() - 1;
        size_t max_j = matrix[0].size() - 1;
        size_t max_move = max_i;
        int num_layer = matrix.size() / 2;
        while (num_layer > 0)
        {
            count = 0;
            sum = 0;
            while (count < max_move)
            {
                cicle(matrix, i, j, max_i, max_j, sum);
                sum++;
                count++;
                j++;
            }
            num_layer--;
            adder++;
            j = 0 + adder;
            i = 0 + adder;
            max_j -= 1;
            max_i -= 1;
            max_move = max_move - 2;
        }
    }
};