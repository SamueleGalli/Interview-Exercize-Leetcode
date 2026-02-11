/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [a^i, b^i] indicates that you must take course b^i first if you want to take course a^i.

    *For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]



Constraints:

    *1 <= numCourses <= 2000
    *0 <= prerequisites.length <= numCourses * (numCourses - 1)
    *prerequisites[i].length == 2
    *0 <= a^i, b^i < numCourses
    *a^i != b^i
    *All the pairs [a^i, b^i] are distinct.


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool loop(vector<vector<int>> &graph, vector<int> &state, int course, vector<int> &result)
    {
        if (state[course] == 2)
            return (true);
        if (state[course] == 1)
            return (false);

        state[course] = 1;

        for (size_t i = 0; i < graph[course].size(); i++)
        {
            if (!loop(graph, state, graph[course][i], result))
                return (false);
        }
        result.push_back(course);
        state[course] = 2;
        return (true);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> state(numCourses, false);
        vector<int> result;

        if (prerequisites.empty())
        {
            for (int i = 0; i < numCourses; i++)
            {
                result.push_back(i);
            }
            return (result);
        }

        for (size_t i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!loop(graph, state, i, result))
            {
                result.clear();
                break;
            }
        }
        reverse(result.begin(), result.end());
        return (result);
    }
};

void print_array(vector<int> result)
{
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "result[" << i << "] = " << result[i] << endl;
    }
}

int main()
{
    Solution s;
    vector<vector<int>> prerequisites;
    vector<int> result;

    prerequisites = {};
    result = s.findOrder(1, prerequisites);
    cout << "result\n";
    print_array(result);
    cout << "\n\n\n";

    prerequisites = {};
    result = s.findOrder(2, prerequisites);
    cout << "result\n";
    print_array(result);
    cout << "\n\n\n";

    prerequisites = {{1, 0}};
    result = s.findOrder(2, prerequisites);
    cout << "result\n";
    print_array(result);
    cout << "\n\n\n";

    prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    result = s.findOrder(4, prerequisites);
    cout << "result\n";
    print_array(result);
    cout << "\n\n\n";

    prerequisites = {{1, 0}, {0, 1}};
    result = s.findOrder(2, prerequisites);
    cout << "result\n";
    print_array(result);
    cout << "\n\n\n";
}
