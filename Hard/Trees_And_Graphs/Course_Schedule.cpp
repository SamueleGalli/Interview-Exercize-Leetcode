/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [a^i, b^i] indicates that you must take course b^i first if you want to take course a^i.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.



Constraints:

    * 1 <= numCourses <= 2000
    * 0 <= prerequisites.length <= 5000
    * prerequisites[i].length == 2
    * 0 <= ai, bi < numCourses
    * All the pairs prerequisites[i] are unique.


*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    void set_graph(vector<vector<int>> &graph, vector<vector<int>> &prerequisites)
    {
        for (size_t i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
    }
    bool loop(vector<vector<int>> &graph, int course, vector<int> &state)
    {
        if (state[course] == 1)
            return (false);
        if (state[course] == 2)
            return (true);

        state[course] = 1;

        for (size_t i = 0; i < graph[course].size(); i++)
        {
            if (!loop(graph, graph[course][i], state))
                return (false);
        }
        state[course] = 2;
        return (true);
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> state(numCourses, 0);

        set_graph(graph, prerequisites);
        
        for (int i = 0; i < numCourses; i++)
        {
            if (!loop(graph, i, state))
                return (false);
        }
        return (true);
    }
};

int main()
{
    Solution s;
    bool result;
    vector<vector<int>> prerequisites;

    prerequisites = {{1, 0}};
    result = s.canFinish(2, prerequisites);
    cout << boolalpha;
    cout << "(result = " << result << " e deve essere true)\n\n\n";

    prerequisites = {};
    result = s.canFinish(1, prerequisites);
    cout << "(result = " << result << " e deve essere true)\n\n\n";

    prerequisites = {{1, 0}, {0, 1}};
    result = s.canFinish(2, prerequisites);
    cout << "(result = " << result << " e deve essere false)\n\n\n";

    prerequisites = {{1, 0}, {2, 1}, {3, 1}, {4, 2}, {5, 3}};
    result = s.canFinish(6, prerequisites);
    cout << "(result = " << result << " e deve essere true)\n\n\n";

    prerequisites = {{1, 0}, {2, 1}, {3, 1}, {4, 2}, {1, 5}};
    result = s.canFinish(6, prerequisites);
    cout << "(result = " << result << " e deve essere true)\n\n\n";

    prerequisites = {{0, 1}};
    result = s.canFinish(2, prerequisites);
    cout << boolalpha;
    cout << "(result = " << result << " e deve essere true)\n\n\n";

    prerequisites = {{2, 1}, {1, 0}};
    result = s.canFinish(3, prerequisites);
    cout << boolalpha;
    cout << "(result = " << result << " e deve essere true)\n\n\n";
}