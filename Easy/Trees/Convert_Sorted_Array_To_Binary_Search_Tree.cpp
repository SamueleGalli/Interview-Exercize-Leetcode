/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

 

Constraints:

    * 1 <= nums.length <= 10^4
    * -10^4 <= nums[i] <= 10^4
    * nums is sorted in a strictly increasing order.


*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <cstddef>
#include <vector>

class Solution
{
private:
    TreeNode *BST_Bilanced(std::vector<int> &nums, int start, int end)
    {
        if (start > end)
            return (nullptr);

        size_t half = (end + start) / 2;
        TreeNode *root = new TreeNode(nums[half]);

        root->left = BST_Bilanced(nums, start, half - 1);
        root->right =  BST_Bilanced(nums, half + 1, end);
        return (root);
    }

public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        if (nums.empty())
            return (nullptr);
        return (BST_Bilanced(nums, 0, nums.size() - 1));
    }
};