/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.



Constraints:

    *1 <= n <= 10^4
*/

using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

class Solution
{
public:
    int perfect_square(int n, vector<vector<int>> &memo, int i = 1, int total = 0)
    {
        if (i >= static_cast<int>(memo.size()) || total > n || i * i > n)
            return 100000;

        if (memo[i][total] != 0)
            return (memo[i][total]);

        if (total == n)
            return (0);

        int result = 100000;

        result = min(result, 1 + perfect_square(n, memo, i, total + (i * i)));
        result = min(result, perfect_square(n, memo, i + 1, total));

        memo[i][total] = result;
        return (result);
    }
    int numSquares(int n)
    {
        vector<vector<int>> memo(floor(sqrt(n)) + 1, vector<int>(n + 1, 0));
        return (perfect_square(n, memo));
    }
};

int main()
{
    Solution s;
    int result;
    int num;

    num = 12;
    result = s.numSquares(num);
    cout << "result = " << result << endl;
    cout << "-------------------------------------------------\n";

    num = 13;
    result = s.numSquares(num);
    cout << "result = " << result << endl;
    cout << "-------------------------------------------------\n";
}