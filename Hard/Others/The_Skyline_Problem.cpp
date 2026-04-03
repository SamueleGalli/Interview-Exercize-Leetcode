/*
A city's skyline is the outer contour of the silhouette formed by all the
buildings in that city when viewed from a distance. Given the locations and
heights of all the buildings, return the skyline formed by these buildings
collectively.

The geometric information of each building is given in the array buildings where
buildings[i] = [left_i, right_i, height_i]:

    * left^i is the x coordinate of the left edge of the i^th building.
    * right^i is the x coordinate of the right edge of the i^th building.
    * height^i is the height of the i^th building.

You may assume all buildings are perfect rectangles grounded on an absolutely
flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their
x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left
endpoint of some horizontal segment in the skyline except the last point in the
list, which always has a y-coordinate 0 and is used to mark the skyline's
termination where the rightmost building ends. Any ground between the leftmost
and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the
output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not
acceptable; the three lines of height 5 should be merged into one in the final
output as such: [...,[2 3],[4 5],[12 7],...]



Example 1:

Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B
represent the key points in the output list.

Example 2:

Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]



Constraints:

    * 1 <= buildings.length <= 10^4
    * 0 <= left_i < right_i <= 2^31 - 1
    * 1 <= height_i <= 2^31 - 1
    * buildings is sorted by lefti in non-decreasing order.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> skyline;
        vector<int> active;
        int height;
        for (vector<int> build : buildings)
        {
            active.push_back(build[0]);
            active.push_back(build[1]);
        }
        sort(active.begin(), active.end());
        active.erase(unique(active.begin(), active.end()), active.end());
        for (const int x : active)
        {
            height = 0;
            for (const vector<int> &build : buildings)
            {
                if (build[1] <= x)
                    continue;
                if (build[0] > x)
                    break;
                if (build[0] <= x && build[1] > x)
                    height = max(height, build[2]);
            }
            if (skyline.empty())
                skyline.push_back({x, height});
            else if (height != skyline.back()[1])
                skyline.push_back({x, height});
        }
        return (skyline);
    }
};

void print_building(vector<vector<int>> &result, int original = 0)
{
    cout << "\n\n\n------------------------------------------------------------------\n";
    if (original == 1)
        cout << "palazzi originali\n\n";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "{";
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j + 1 < result[i].size())
                cout << ", ";
        }
        cout << "}";
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "\n------------------------------------------------------------------\n\n\n\n";
}

int main()
{
    vector<vector<int>> buildings;
    vector<vector<int>> result;
    Solution s;

    buildings = {{0, 2147483647, 2147483647}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2, 9, 30}, {2, 10, 20}, {2, 12, 9}, {2, 15, 2}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2, 9, 10}, {2, 10, 20}, {2, 12, 30}, {2, 15, 32}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2, 10, 10}, {2, 12, 20}, {2, 15, 9}, {2, 17, 2}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2, 10, 30}, {2, 12, 20}, {2, 15, 10}, {2, 17, 15}, {2, 19, 20}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2, 15, 10}, {4, 15, 20}, {6, 15, 22}, {9, 15, 25}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2, 15, 30}, {4, 15, 20}, {6, 15, 9}, {10, 15, 2}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2, 15, 30}, {4, 15, 20}, {6, 15, 10}, {9, 15, 15}, {10, 15, 20}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{1, 2, 1}, {1, 2, 2}, {1, 2, 3}, {2, 3, 1}, {2, 3, 2}, {2, 3, 3}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{0, 2, 3}, {2, 5, 3}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);

    buildings = {{2,4,7}, {5,9,10}, {10,12,6}};
    result = s.getSkyline(buildings);
    print_building(buildings, 1);
    print_building(result);
}
