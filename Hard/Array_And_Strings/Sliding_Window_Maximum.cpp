/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]



Constraints:

    * 1 <= nums.length <= 10^5
    * -10^4 <= nums[i] <= 10^4
    * 1 <= k <= nums.length

*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void print_vec(vector<int> vec)
{
    cout << "\nVECTOR\n";
    cout << "\n-----------------------------------------------\n";
    for (size_t i = 0; i < vec.size(); i++)
        cout << "vec[" << i << "] = " << vec[i] << endl;
    cout << "\n-----------------------------------------------\n";
}

void deque_attuale(deque<int> deque, vector<int> nums)
{
    cout << "\nDEQUE\n";
    for (size_t i = 0; i < deque.size(); i++)
    {
        // cout << "deque[" << i << "] = " << deque[i] << endl;
        cout << "nums[" << deque[i] << "] = " << nums[deque[i]] << endl;
    }
    cout << "FINE LETTURA DEQUE\n";
}

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        deque<int> aux;
        int start;
        for (int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            if (i - k + 1 < 0)
                start = -1;
            else
                start = i - k + 1;
            while (!aux.empty() && aux.back() < start)
                aux.pop_back();
            while (!aux.empty() && nums[i] > nums[aux.front()])
                aux.pop_front();
            aux.push_front(i);
            if (i >= k - 1)
                result.push_back(nums[aux.back()]);
        }
        return (result);
    }
};

int main()
{
    vector<int> vec = { 1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;
    vector<int> result;
    result = s.maxSlidingWindow(vec, 3);
    print_vec(result);
    vec = {1};
    result = s.maxSlidingWindow(vec, 1);
    print_vec(result);
    vec = {1, -1};
    result = s.maxSlidingWindow(vec, 1);
    print_vec(result);
    vec = {9, 11};
    result = s.maxSlidingWindow(vec, 2);
    print_vec(result);
    vec = {6, 1, 3, 8, -1, -3, 5, 20, 3, 6, 7, 80};
    result = s.maxSlidingWindow(vec, 2);
    print_vec(result);
};
