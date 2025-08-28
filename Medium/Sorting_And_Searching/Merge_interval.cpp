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