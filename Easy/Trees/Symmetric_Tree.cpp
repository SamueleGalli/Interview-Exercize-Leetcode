struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private:
        bool simmetric_childs(TreeNode *left, TreeNode *right)
        {
            if (left && right)
            {
                if (left->val == right->val)
                {
                    if (simmetric_childs(left->left, right->right) == false)
                        return (false);
                    if (simmetric_childs(left->right, right->left) == false)
                        return (false);
                    return (true);
                }
                else
                    return(false);
            }
            else if (!left && !right)
                return (true);
            else
                return (false);
        }
public:
    bool isSymmetric(TreeNode* root)
    {
        if (!root)
            return (true);
        return (simmetric_childs(root->left, root->right));
    }
};