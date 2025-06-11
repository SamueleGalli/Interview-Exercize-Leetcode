struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <climits>

class Solution
{
private:
    bool limit(TreeNode *root, long long min, long long max)
    {
        if (root)
        {
            if (root->val > min && root->val < max)
            {
                if (limit(root->left, min, root->val) == false)
                    return (false);
                if (limit(root->right, root->val, max) == false)
                    return (false);
            }
            else
                return(false);
        }
        return(true);
    }
public:
    bool isValidBST(TreeNode *root)
    {
        if (limit(root, LLONG_MIN, LLONG_MAX) == 1)
            return (true);
        return (false);
    }
};