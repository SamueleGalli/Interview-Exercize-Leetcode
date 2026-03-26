/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9



Constraints:

    n == height.length
    1 <= n <= 2 * 10^4
    0 <= height[i] <= 10^5
*/

    using namespace std;

    #include <iostream>
    #include <vector>
    #include <algorithm>

    class Solution
    {
    public:
        int trap(vector<int> &height)
        {
            int water = 0;
            size_t r = height.size() - 1;
            size_t l = 0;
            int left_max = 0;
            int right_max = 0;
            while (l < r)
            {
                if (height[l] <= height[r])
                    left_max = max(left_max, height[l++]);
                else
                    right_max = max(right_max, height[r--]);

                if (height[l] < left_max)
                    water += left_max - height[l];
                else if (height[r] < right_max)
                    water += right_max - height[r];
            }
            return (water);
        }
    };

int main()
{
    Solution s;
    int result;
    vector<int> height;

    height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    result = s.trap(height);
    cout << "il risultato e " << result << endl;

    height = {4, 2, 0, 3, 2, 5};
    result = s.trap(height);
    cout << "il risultato e " << result << endl;

    height = {0};
    result = s.trap(height);
    cout << "il risultato e " << result << endl;

    height = {0, 2};
    result = s.trap(height);
    cout << "il risultato e " << result << endl;

    height = {3, 0, 2};
    result = s.trap(height);
    cout << "il risultato e " << result << endl;
}