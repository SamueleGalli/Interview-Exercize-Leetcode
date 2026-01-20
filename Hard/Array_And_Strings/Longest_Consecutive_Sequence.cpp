/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3

 

Constraints:

    * 0 <= nums.length <= 10^5
    * -10^9 <= nums[i] <= 10^9
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        if (nums.size() == 0)
            return (0);
        int longest = 1;
        int temp_longest = 1;
        sort(nums.begin(), nums.end());
        int value = nums.at(0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (value + 1 == nums.at(i))
            {
                value = nums.at(i);
                temp_longest++;
            }
            else if (value == nums.at(i))
                continue;
            else
            {
                value = nums.at(i);
                if (temp_longest > longest)
                    longest = temp_longest;
                temp_longest = 1;
            }
        }
        if (temp_longest > longest)
            longest = temp_longest;
        return (longest);
    }
};

/* int main()
{
    Solution *result = new Solution();
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int final_result = result->longestConsecutive(nums);
    cout << "result of = " << final_result << endl;
    cout << "----------------------------------------------------------------------------\n";
    nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    final_result = result->longestConsecutive(nums);
    cout << "result of = " << final_result << endl;
    cout << "----------------------------------------------------------------------------\n";
    nums = {1, 0, 1, 2};
    final_result = result->longestConsecutive(nums);
    cout << "result of = " << final_result << endl;
    cout << "----------------------------------------------------------------------------\n";
    nums = {};
    final_result = result->longestConsecutive(nums);
    cout << "result of = " << final_result << endl;
    cout << "----------------------------------------------------------------------------\n";
    nums = {1};
    final_result = result->longestConsecutive(nums);
    cout << "result of = " << final_result << endl;
    cout << "----------------------------------------------------------------------------\n";
    nums = {1, 2, 6, 7, 8};
    final_result = result->longestConsecutive(nums);
    cout << "result of = " << final_result << endl;
    delete (result);
} */