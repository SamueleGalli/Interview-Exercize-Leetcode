/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.



Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]



Constraints:

    * 1 <= nums.length <= 5 * 10^4
    * 0 <= nums[i] <= 5000
    * It is guaranteed that there will be an answer for the given input nums.


Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        size_t center = (nums.size() - 1) / 2;
        size_t small = center;
        size_t big = nums.size() - 1;
        vector<int> temp = nums;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (static_cast<int>(i + 1) % 2 == 0)
                nums[i] = temp[big--];
            else
                nums[i] = temp[small--];
        }
    }
};

void print_sorted(vector<int> nums)
{
    cout << "sorted nums\n\n";
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << "nums[" << i << "] = " << nums[i] << endl;
    }
    cout << "fine stampa numeri\n\n";
}

int main()
{
    Solution s;
    vector<int> nums;

    nums = {1, 5, 1, 1, 6, 4};
    s.wiggleSort(nums);
    print_sorted(nums);

    nums = {1, 3, 2, 2, 3, 1};
    s.wiggleSort(nums);
    print_sorted(nums);
    
    nums = {5, 5, 5, 4, 4, 4, 4};
    s.wiggleSort(nums);
    print_sorted(nums);
}