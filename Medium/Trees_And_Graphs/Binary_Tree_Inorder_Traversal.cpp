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
private:
    void all_tree(TreeNode *root, std::vector<int> &result)
    {
        if (!root)
            return;
        if (root->left)
            all_tree(root->left, result);
        result.push_back(root->val);
        if (root->right)
            all_tree(root->right, result);
    }

public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        if (!root)
            return result;
        all_tree(root, result);
        return result;
    }
};