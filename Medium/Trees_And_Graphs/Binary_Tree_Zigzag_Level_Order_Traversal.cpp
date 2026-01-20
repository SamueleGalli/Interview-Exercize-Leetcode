/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    * The number of nodes in the tree is in the range [0, 2000].
    * -100 <= Node.val <= 100


*/

#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    void loop_tree(std::vector<std::vector<int>> &result, TreeNode *root, unsigned int deep)
    {
        if (!root)
            return;
        if (deep == result.size())
            result.push_back({});
        if (deep % 2 == 0)
            result[deep].push_back(root->val);
        else
            result[deep].insert(result[deep].begin(), root->val);
        loop_tree(result, root->left, deep + 1);
        loop_tree(result, root->right, deep + 1);
    }

public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        loop_tree(result, root, 0);
        return (result);
    }
};