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