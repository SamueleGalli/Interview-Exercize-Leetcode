/*
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].



Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:

Input: nums = [-1]
Output: [0]

Example 3:

Input: nums = [-1,-1]
Output: [0,0]



Constraints:

    * 1 <= nums.length <= 10^5
    * -10^4 <= nums[i] <= 10^4


*/

using namespace std;

#include <iostream>
#include <vector>

void print_smaller(vector<int> result)
{
    cout << "\n\n IL RISULTATO \n\nE\n\n";
    for (size_t i = 0; i < result.size(); i++)
        cout << "result[" << i << "] = " << result[i] << endl;
}
//TODO binary search sbagliato
class Solution
{
public:
    int binary_search(int number, vector<int> &ordered)
    {
        if (ordered.empty())
        {
            ordered.push_back(number);
            return (0);
        }
        else if (ordered.size() == 1)
        {
            if (number > ordered[0])
            {
                ordered.push_back(number);
                return (1);
            }
            else
            {
                ordered.insert(ordered.begin(), number);
                return (0);
            }
        }

        size_t start = 0;
        size_t end = (ordered.size() - 1);
        size_t middle;
        while (start < end)
        {
            middle = end + start / 2;
            //cout << number << " > " << ordered[middle] << "\n\n\n";
            if (number > ordered[middle])
                start = middle + 1;
            else
                end = middle - 1;
        }
        /*cout << "ordered[start] = " << ordered[start] << endl;
        cout << "ordered[end] = " << ordered[end] << endl;
        cout << "ordered[middle] = " << ordered[middle] << endl;*/
        if (middle < start)
            middle++;
        ordered.insert(ordered.begin() + middle, number);
        return (static_cast<int>(middle));
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        vector<int> ordered;
        size_t i;

        i = nums.size();
        do
        {
            i--;
            result[i] = binary_search(nums[i], ordered);
        } while (i != 0);
        cout << "finale ordered\n";
        print_smaller(ordered);
        return (result);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> result;

    /*nums = {5, 2, 6, 1};
    result = s.countSmaller(nums);
    print_smaller(result);
    cout << "\n--------------------------------------------------------------------------------\n";

    nums = {-1};
    result = s.countSmaller(nums);
    print_smaller(result);
    cout << "\n--------------------------------------------------------------------------------\n";

    nums = {-1, -1};
    result = s.countSmaller(nums);
    print_smaller(result);
    cout << "\n--------------------------------------------------------------------------------\n";

    nums = {-1, -1, 1, 0, -2};
    result = s.countSmaller(nums);
    print_smaller(result);
    cout << "\n--------------------------------------------------------------------------------\n";*/

    nums = {0, 2, 1};
    result = s.countSmaller(nums);
    print_smaller(result);
    cout << "\n--------------------------------------------------------------------------------\n";

    /*nums = {2, 0, 1};
    result = s.countSmaller(nums);
    print_smaller(result);

    nums = {26, 78, 27, 100, 33, 67, 90, 23, 66, 5, 38, 7, 35, 23, 52, 22, 83, 51, 98,
            69, 81, 32, 78, 28, 94, 13, 2, 97, 3, 76, 99, 51, 9, 21, 84, 66, 65, 36, 100, 41};
    nums = {97, 3, 76, 99, 51, 9, 21, 84, 66, 65, 36, 100, 41};
    result = s.countSmaller(nums);
    print_smaller(result);*/
}