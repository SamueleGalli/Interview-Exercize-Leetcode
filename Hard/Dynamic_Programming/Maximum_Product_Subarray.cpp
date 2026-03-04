/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.



Constraints:

    * 1 <= nums.length <= 2 * 10^4
    * -10 <= nums[i] <= 10
    * The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int my_max = nums[0];
        int my_min = nums[0];
        int total_max = nums[0];
        int prev_max;

        for (size_t i = 1; i < nums.size(); i++)
        {
            prev_max = my_max;

            my_max = max(my_min * nums[i], max(my_max * nums[i], nums[i]));

            my_min = min(prev_max * nums[i], min(my_min * nums[i], nums[i]));

            total_max = max(total_max, max(my_max, my_min));
        }
        return (total_max);
    }
};

int main()
{
    Solution s;
    int result;
    vector<int> nums;

    nums = {-6};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {-5};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {-2};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {-2, 3, -4};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {2, 3, -2, 4};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {-2, 0, -1};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {-2, 0, -3, -4};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {1, -2, -3, 0, 7, -8, -2};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {0, 0, 0};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {-1, -2, -3, -4};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {-2, 0, -1, 4};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {0, -3, 1, -2};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {2, 3, -2, 4, 9, -1, 0, 12, -40, 123};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {3, -1, 4};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";

    nums = {7, 0};
    result = s.maxProduct(nums);
    cout << "\n\n\n(risultato = " << result << ")\n\n\n";
}