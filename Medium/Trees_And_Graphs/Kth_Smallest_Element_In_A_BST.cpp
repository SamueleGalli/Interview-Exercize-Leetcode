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
    TreeNode *cycle(TreeNode *root, int &k)
    {
        TreeNode *Node = nullptr;
        if (root->left != nullptr)
        {
            Node = cycle(root->left, k);
            if (Node != nullptr)
                return (Node);
        }
        k--;
        if (k == 0)
            return new TreeNode(root->val);
        if (root->right != nullptr)
        {
            Node = cycle(root->right, k);
            if (Node != nullptr)
                return (Node);
        }
        return nullptr;
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
            return (0);
        TreeNode *smallest = cycle(root, k);
        int smal = smallest->val;
        if (smallest)
            delete smallest;
        return (smal);
    }
};