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