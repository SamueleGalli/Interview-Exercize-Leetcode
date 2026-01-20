/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

 

Constraints:

    * The number of nodes in the tree is in the range [1, 1000].
    * -100 <= Node.val <= 100

 
Follow up: Could you solve it both recursively and iteratively?
*/

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