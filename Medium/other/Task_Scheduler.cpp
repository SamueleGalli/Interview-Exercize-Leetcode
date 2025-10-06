#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> task_manager;
        int max_time = 0;
        int max_feq;
        for (size_t i = 0;i < tasks.size();i++)
        {
            task_manager[tasks[i]]++;
        }
        for (auto i = task_manager.begin(); i != task_manager.end(); i++)
        {
            if (i->second > max_time)
            {
                max_feq = 1;
                max_time = i->second;
            }
            else if (i->second == max_time)
            {
                max_feq++;
            }
        }
        return(max((int)tasks.size(), (max_time - 1) * (n + 1) + max_feq));
    }
};