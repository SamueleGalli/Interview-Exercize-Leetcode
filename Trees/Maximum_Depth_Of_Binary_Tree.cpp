struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return (0);
        int left_i = maxDepth(root->left);
        int right_i = maxDepth(root->right);
        int total = 0;
        if (left_i > right_i)
            total = left_i;
        else
            total = right_i;
        return (++total);
    }
};
