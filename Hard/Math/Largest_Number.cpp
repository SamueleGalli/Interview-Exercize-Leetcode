/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.



Example 1:

Input: nums = [10,2]
Output: "210"

Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"



Constraints:

    * 1 <= nums.length <= 100
    * 0 <= nums[i] <= 10^9

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string result;
        vector<string> str_num;
        string num1;
        string num2;

        for (size_t i = 0; i < nums.size(); i++)
        {
            str_num.push_back(to_string(nums[i]));
        }
        sort(str_num.begin(), str_num.end(), [](string &num1, string &num2) -> bool
             {
            if (num1 + num2 > num2 + num1)
                return (true);
            else
                return (false); });
        if (str_num[0] == "0")
            return ("0");
        for (size_t i = 0; i < str_num.size(); i++)
        {
            result += str_num[i];
        }
        return (result);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    string result;

    nums = {10, 2};
    result = s.largestNumber(nums);
    cout << "result = " << result << endl;
    nums = {3, 30, 34, 5, 9};
    result = s.largestNumber(nums);
    cout << "result = " << result << endl;
    nums = {0, 0};
    result = s.largestNumber(nums);
    cout << "result = " << result << endl;
}