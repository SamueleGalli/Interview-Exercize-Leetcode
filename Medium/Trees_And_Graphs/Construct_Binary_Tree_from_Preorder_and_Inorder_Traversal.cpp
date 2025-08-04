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
    TreeNode  *create_tree(std::vector<int> &preorder,size_t start_P, size_t end_P , size_t start_I,size_t end_I, std::vector<int> &inorder)
    {
        if (start_P > end_P)
            return (nullptr);
        TreeNode *root = new TreeNode(preorder[start_P]);
        size_t i_inorder = 0;
        for (;i_inorder < end_I; i_inorder++)
        {
            if (inorder[i_inorder] == preorder[start_P])
                break;
        }
        root->left = create_tree(preorder, start_P + 1, start_P + (i_inorder - start_I), start_I,i_inorder - 1, inorder);
        root->right = create_tree(preorder,start_P + (i_inorder - start_I) + 1, end_P, i_inorder + 1, end_I, inorder);
        return (root);
    }
public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        return (create_tree(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorder));
    }
};