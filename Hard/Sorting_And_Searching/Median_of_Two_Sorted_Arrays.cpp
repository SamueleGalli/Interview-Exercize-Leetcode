/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.



Constraints:

    * nums1.length == m
    * nums2.length == n
    * 0 <= m <= 1000
    * 0 <= n <= 1000
    * 1 <= m + n <= 2000
    * -10^6 <= nums1[i], nums2[i] <= 10^6

*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    void fill_merged(vector<int> &num, size_t i, vector<double> &merged)
    {
        while (i < num.size())
            merged.push_back(static_cast<double>(num[i++]));
    }
    void merging(size_t i, size_t j, vector<int> &nums1, vector<int> &nums2, vector<double> &merged)
    {
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
                merged.push_back(static_cast<double>(nums1[i++]));
            else if (nums2[j] <= nums1[i])
                merged.push_back(static_cast<double>(nums2[j++]));
        }
        if (i < nums1.size())
            fill_merged(nums1, i, merged);
        else if (j < nums2.size())
            fill_merged(nums2, j, merged);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<double> merged;
        double result = 0.0;
        if (nums1.empty() && nums2.empty())
            return (result);
        merging(0, 0, nums1, nums2, merged);
        if (merged.size() % 2 == 1)
            result = merged[merged.size() / 2];
        else
            result = (merged[merged.size() / 2] + merged[(merged.size() / 2) - 1]) / 2;
        return (result);
    }
};

int main()
{
    Solution s;
    double result;
    vector<int> nums1;
    vector<int> nums2;

    nums1 = {1, 3};
    nums2 = {2};
    result = s.findMedianSortedArrays(nums1, nums2);
    cout << "il risultato e = " << result << "\n\n";

    nums1 = {1, 2};
    nums2 = {3, 4};
    result = s.findMedianSortedArrays(nums1, nums2);
    cout << "il risultato e = " << result << "\n\n";

    nums1 = {3, 4};
    nums2 = {1, 2};
    result = s.findMedianSortedArrays(nums1, nums2);
    cout << "il risultato e = " << result << "\n\n";

    nums1 = {};
    nums2 = {1, 2};
    result = s.findMedianSortedArrays(nums1, nums2);
    cout << "il risultato e = " << result << "\n\n";

    nums1 = {3, 4};
    nums2 = {};
    result = s.findMedianSortedArrays(nums1, nums2);
    cout << "il risultato e = " << result << "\n\n";

    nums1 = {};
    nums2 = {};
    result = s.findMedianSortedArrays(nums1, nums2);
    cout << "il risultato e = " << result << "\n\n";

    nums1 = {3, 3, 3, 4};
    nums2 = {1, 2, 2, 2, 5};
    result = s.findMedianSortedArrays(nums1, nums2);
    cout << "il risultato e = " << result << "\n\n";
}