/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”



Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1



Constraints:

    * The number of nodes in the tree is in the range [2, 10^5].
    * -10^9 <= Node.val <= 10^9
    * All Node.val are unique.
    * p != q
    * p and q will exist in the tree.


*/

#include <stdlib.h>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *left_node;
        TreeNode *right_node;

        if (!root)
            return (NULL);
        if (root == q || root == p)
            return (root);
        left_node = lowestCommonAncestor(root->left, p, q);
        right_node = lowestCommonAncestor(root->right, p, q);
        if (left_node && right_node)
            return (root);
        if (left_node)
            return (left_node);
        else if (right_node)
            return (right_node);
        return (NULL);
    }
};

void remove_tree(TreeNode *&head)
{
    if (!head)
        return;
    remove_tree(head->left);
    remove_tree(head->right);
    delete (head);
    head = NULL;
}

int main()
{
    Solution s;
    TreeNode *head;
    TreeNode *result;

    head = new TreeNode(3);

    head->left = new TreeNode(5);
    head->right = new TreeNode(1);

    head->right->right = new TreeNode(8);
    head->right->left = new TreeNode(0);

    head->left->left = new TreeNode(6);
    head->left->right = new TreeNode(2);
    head->left->right->right = new TreeNode(4);
    head->left->right->left = new TreeNode(7);

    result = s.lowestCommonAncestor(head, head->left, head->right);
    if (result)
        cout << "lowest Common Ancestor = " << result->val << "\n\n\n";
    result = s.lowestCommonAncestor(head, head->left, head->left->right->right);
    if (result)
        cout << "lowest Common Ancestor = " << result->val << "\n\n\n";

    remove_tree(head);

    head = new TreeNode(1);
    head->right = new TreeNode(2);
    result = s.lowestCommonAncestor(head, head, head->right);
    if (result)
        cout << "lowest Common Ancestor = " << result->val << "\n\n\n";

    remove_tree(head);
}