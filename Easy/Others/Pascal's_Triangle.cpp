/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

 

Constraints:

    * 1 <= numRows <= 30


*/

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> tringle;
        for (int i = 0; i < numRows; i++)
        {
            //vettore colonna triangolare con tutti gli elementi a 1
            std::vector<int> col(i + 1, 1);
            tringle.push_back(col);
        }
        if (numRows == 1 || numRows == 2)
            return tringle;
        int cell;
        int col;
        for (int i = 2; i < numRows; i++)
        {
            cell = 0;
            col = i - 1;
            for (size_t j = 1; j < tringle[i].size() - 1; j++)
            {
                tringle[i][j] = tringle[col][cell] + tringle[col][cell + 1];
                cell++;
            }
            
        }
        return (tringle);
    }
};