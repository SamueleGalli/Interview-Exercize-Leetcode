/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

 

Constraints:

    * n == height.length
    * 2 <= n <= 10^5
    * 0 <= height[i] <= 10^4
*/

#include <vector>

using namespace std;

class Solution
{
private:
    int min(int n1, int n2)
    {
        if (n1 < n2)
            return (n1);
        return (n2);
    }

public:
    int maxArea(vector<int> &height)
    {
        size_t j = height.size() - 1;
        int max_area = 0;
        int water_height = 0;
        int temp_calc = 0;
        for (size_t i = 0; i < height.size();)
        {
            water_height = height[j];
            temp_calc = min(water_height, height[i]) * (j - i);
            if (temp_calc > max_area)
                max_area =  temp_calc;
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return (max_area);
    }
};
