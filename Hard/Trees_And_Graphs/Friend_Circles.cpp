/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the i^th city and the j^th city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3



Constraints:

    * 1 <= n <= 200
    * n == isConnected.length
    * n == isConnected[i].length
    * isConnected[i][j] is 1 or 0.
    * isConnected[i][i] == 1
    * isConnected[i][j] == isConnected[j][i]

*/

using namespace std;

#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
    void find_city(vector<vector<int>> &isConnected, size_t i, size_t j)
    {
        while (j < isConnected[i].size())
        {
            if (isConnected[i][j] == 1)
            {
                isConnected[i][j] = -1;
                if (isConnected[j][i] == 1 && j != i)
                {
                    isConnected[j][i] = -1;
                    find_city(isConnected, j, 0);
                }
            }
            j++;
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int city = 0;

        for (size_t i = 0; i < isConnected.size(); i++)
        {
            for (size_t j = 0; j < isConnected[i].size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    city++;
                    find_city(isConnected, i, 0);
                }
            }
        }
        return (city);
    }
};

int main()
{
    Solution s;
    int result;
    vector<vector<int>> map;

    map = {{1, 1, 0},
           {1, 1, 0},
           {0, 0, 1}};

    result = s.findCircleNum(map);
    cout << "resulted provinces = " << result << endl;

    map = {{1, 0, 0},
           {0, 1, 0},
           {0, 0, 1}};

    result = s.findCircleNum(map);
    cout << "resulted provinces = " << result << endl;

    map = {{1, 0, 1, 0},
           {0, 1, 0, 1},
           {1, 0, 1, 0},
           {0, 1, 0, 1}};

    result = s.findCircleNum(map);
    cout << "resulted provinces = " << result << endl;

    map = {{0, 1, 0, 1},
           {1, 0, 1, 0},
           {0, 1, 0, 1},
           {1, 0, 1, 0}};

    result = s.findCircleNum(map);
    cout << "resulted provinces = " << result << endl;

    map = {{1, 0, 0, 1},
           {0, 1, 1, 0},
           {0, 1, 1, 1},
           {1, 0, 1, 1}};

    result = s.findCircleNum(map);
    cout << "resulted provinces = " << result << endl;
}