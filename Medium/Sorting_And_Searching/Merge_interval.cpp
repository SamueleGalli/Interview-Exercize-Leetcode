/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.

 

Constraints:

    * 1 <= intervals.length <= 10^4
    * intervals[i].length == 2
    * 0 <= starti <= endi <= 10^4


*/

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        int start = -10;
        int end = -10;
        std::vector<std::vector<int>> new_intervals;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &a, std::vector<int> &b)
                  { return a[0] < b[0]; });
        for (size_t i = 0; i < intervals.size(); i++)
        {
            if (start == -10 && end == -10)
            {
                end = intervals[i][1];
                start = intervals[i][0];
            }
            if (i + 1 < intervals.size())
            {
                if (end >= intervals[i + 1][0] || (end == intervals[i + 1][1] && start == intervals[i + 1][0]))
                {
                    start = std::min(intervals[i + 1][0], start);
                    end = std::max(intervals[i + 1][1], end);
                    continue;
                }
            }
            new_intervals.push_back({start, end});
            start = -10;
            end = -10;
        }
        return (new_intervals);
    }
};