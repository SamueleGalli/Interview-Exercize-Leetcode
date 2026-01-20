/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

 

Constraints:

    * The number of nodes in the tree is n.
    * 1 <= k <= n <= 10^4
    * 0 <= Node.val <= 10^4

 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

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