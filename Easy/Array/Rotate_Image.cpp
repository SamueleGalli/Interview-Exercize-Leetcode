#include <iostream>
#include <algorithm>
#include <vector>

/*
    ciclo esterno funziona interno no(capire numero di cicli interni e ciclare correttamente l'interno)
*/
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