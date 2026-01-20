/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

    * 1 <= nums.length <= 10^5
    * -10^4 <= nums[i] <= 10^4
    * k is in the range [1, the number of unique elements in the array].
    * It is guaranteed that the answer is unique.

 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::map<int, int> ordered;
        for (int value : nums)
        {
            ordered[value]++;
        }

        std::vector<std::pair<int, int>> paired;
        for (std::pair<int, int> pair : ordered)
        {
            paired.push_back({pair.first, pair.second});
        }
        std::vector<int> result;
        //[valori esterni],(elementi di pairs){funzione speciale Lambda}
        std::sort(paired.begin(), paired.end(), [](std::pair<int, int> &a, std::pair<int, int> &b)
        {
            if (b.second > a.second)
                return (false);
            return (true); 
        });
        for (int i = 0; i < k; i++)
        {
            result.push_back(paired[i].first);
        }
        return (result);
    }
};