/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.



Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4



Constraints:

    * 1 <= points.length <= 300
    * points[i].length == 2
    * -10^4 <= xi, yi <= 10^4
    * All the points are unique.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <map>

class Solution
{
private:
    int gcd(int x, int y)
    {
        int result;

        x = abs(x);
        y = abs(y);

        if (y == 0)
            return (x);

        result = gcd(y, x % y);

        return (result);
    }

    int get_points(vector<vector<int>> &points, map<pair<int, int>, int> &occurences, size_t i)
    {
        int result = 0;
        int x = 0;
        int y = 0;

        for (size_t j = 0; j < points.size(); j++)
        {
            x = points[j][0] - points[i][0];
            y = points[j][1] - points[i][1];
            if (i != j)
            {
                if (x == 0)
                    occurences[{x, 1}]++;
                else if (y == 0)
                    occurences[{1, y}]++;
                else
                {
                    int divisor = gcd(x, y);

                    x = x / divisor;
                    y = y / divisor;
                    if (x < 0)
                    {
                        x = -x;
                        y = -y;
                    }
                    occurences[{x, y}]++;
                }
            }
        }
        for (auto value : occurences)
            result = max(result, value.second);
        return (result);
    }

public:
    int maxPoints(vector<vector<int>> &points)
    {
        map<pair<int, int>, int> occurences;
        int total = 0;

        for (size_t i = 0; i < points.size(); i++)
        {
            total = max(total, get_points(points, occurences, i) + 1);
            occurences.clear();
        }
        return (total);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points;
    int maxP;

    points = {{1, 1}};
    maxP = s.maxPoints(points);
    cout << "maxP = " << maxP << endl;

    points = {{1, 1}, {2, 2}};
    maxP = s.maxPoints(points);
    cout << "maxP = " << maxP << endl;

    points = {{1, 1}, {2, 2}, {3, 3}};
    maxP = s.maxPoints(points);
    cout << "maxP = " << maxP << endl;

    points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    maxP = s.maxPoints(points);
    cout << "maxP = " << maxP << endl;

    points = {{0, 0}, {4, 5}, {7, 8}, {8, 9}, {5, 6}, {3, 4}, {1, 1}};
    maxP = s.maxPoints(points);
    cout << "maxP = " << maxP << endl;

    points = {{2, 3}, {3, 3}, {-5, 3}};
    maxP = s.maxPoints(points);
    cout << "maxP = " << maxP << endl;
}
