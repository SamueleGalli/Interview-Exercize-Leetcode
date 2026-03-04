/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).



Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:

Input: matrix = [[-5]], k = 1
Output: -5



Constraints:

    * n == matrix.length == matrix[i].length
    * 1 <= n <= 300
    * -109 <= matrix[i][j] <= 109
    * All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
    * 1 <= k <= n2



Follow up:

    * Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
    * Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.

*/
using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int max = matrix[0][0];
        size_t j = 0;
        size_t i = 0;
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> stack;
        vector<vector<bool>> taken(matrix.size(), vector<bool>(matrix.size(), false));

        taken[0][0] = true;
        for (int count = 1; count < k; count++)
        {
            if (i + 1 < matrix.size() && !taken[i + 1][j])
            {
                stack.push({matrix[i + 1][j], i + 1, j});
                taken[i + 1][j] = true;
            }
            if (j + 1 < matrix[i].size() && !taken[i][j + 1])
            {
                stack.push({matrix[i][j + 1], i, j + 1});
                taken[i][j + 1] = true;
            }
            max = get<0>(stack.top());
            i = get<1>(stack.top());
            j = get<2>(stack.top());
            stack.pop();
        }
        return (max);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;
    int result, k;

    k = 8;
    matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}};
    result = s.kthSmallest(matrix, k);
    cout << "result = " << result << endl;

    k = 1;
    matrix = {{-5}};
    result = s.kthSmallest(matrix, k);
    cout << "result = " << result << endl;

    matrix = {
        {1, 5, 9},
        {2, 6, 10},
        {3, 7, 11}};
    k = 5;
    result = s.kthSmallest(matrix, k);
    cout << "result = " << result << endl;
}