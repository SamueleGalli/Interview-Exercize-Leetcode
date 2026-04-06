/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4



Constraints:

    1 <= heights.length <= 10^5
    0 <= heights[i] <= 10^4
*/

using namespace std;

#include <vector>
#include <iostream>
#include <queue>

class Solution
{
public:
    int give_max(deque<size_t> &range, const vector<int> &heights,
                 const size_t i, int result,
                 int value = 0, int occurences = 0)
    {
        while (!range.empty())
        {
            if (i < heights.size() && heights[range.back()] < heights[i])
                break;
            value = heights[range.back()];
            range.pop_back();
            if (range.empty())
                occurences = i;
            else
                occurences = i - range.back() - 1;
            result = max(result, occurences * value);
        }
        return (result);
    }

    int largestRectangleArea(vector<int> &heights)
    {
        deque<size_t> range;
        int result = 0;
        size_t i = 0;
        for (; i < heights.size(); i++)
        {
            if (range.empty() || heights[range.back()] < heights[i])
                range.push_back(i);
            else
            {
                result = give_max(range, heights, i, result);
                range.push_back(i);
            }
        }
        result = give_max(range, heights, i, result);
        return (result);
    }
};

int main()
{
    vector<int> heights;
    Solution s;
    int result;

    heights = {2, 1, 5, 6, 2, 3};
    result = s.largestRectangleArea(heights);
    cout << "result = " << result << endl;

    heights = {2, 4};
    result = s.largestRectangleArea(heights);
    cout << "result = " << result << endl;
}