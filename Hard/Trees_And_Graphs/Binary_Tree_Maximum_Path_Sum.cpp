/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.



Example 1:

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.



Constraints:

    The number of nodes in the tree is in the range [1, 3 * 10^4].
    -1000 <= Node.val <= 1000

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

#include <iostream>
#include <climits>

int result;

class Solution
{
public:
    int find_max(int right_node, int left_node, int temp_result)
    {
        int node = temp_result;
        int right_arm = right_node + node;
        int left_arm = left_node + node;

        if (left_arm > temp_result)
            temp_result = left_arm;
        if (right_arm > temp_result)
            temp_result = right_arm;

        if (node > result)
            result = node;
        if (right_arm > result)
            result = right_arm;
        if (left_arm > result)
            result = left_arm;
        if (node + left_node + right_node > result)
            result = node + left_node + right_node;

        return (temp_result);
    }
    int max_finded_leaves(TreeNode *root)
    {
        int left_node = 0;
        int right_node = 0;
        int temp_result = root->val;

        if (root->left)
            left_node = max_finded_leaves(root->left);
        if (root->right)
            right_node = max_finded_leaves(root->right);

        return (find_max(right_node, left_node, temp_result));
    }

    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return (0);
        if (!root->left && !root->right)
            return (root->val);
        result = INT_MIN;
        max_finded_leaves(root);
        return (result);
    }
};

void delete_tree(TreeNode *root)
{
    if (!root)
        return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete (root);
    root = nullptr;
}

int main()
{
    Solution s;
    TreeNode *head;
    int result;

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);

    result = s.maxPathSum(head);
    cout << "\n(result finale = " << result << ")\n";

    delete_tree(head);

    head = new TreeNode(-10);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->right = new TreeNode(7);
    head->right->left = new TreeNode(15);

    result = s.maxPathSum(head);
    cout << "\n(result = " << result << ")\n";

    delete_tree(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(100);
    head->right = new TreeNode(3);

    result = s.maxPathSum(head);
    cout << "\n(result = " << result << ")\n";

    delete_tree(head);

    head = new TreeNode(-3);

    result = s.maxPathSum(head);
    cout << "\n(result = " << result << ")\n";

    delete_tree(head);

    head = new TreeNode(1);
    head->right = new TreeNode(-3);
    head->right->left = new TreeNode(-2);
    head->left = new TreeNode(-2);
    head->left->right = new TreeNode(3);
    head->left->left = new TreeNode(1);
    head->left->left->left = new TreeNode(-1);

    result = s.maxPathSum(head);
    cout << "\n(result = " << result << ")\n";

    delete_tree(head);

    head = new TreeNode(-2);
    head->right = new TreeNode(-1);

    result = s.maxPathSum(head);
    cout << "\n(result = " << result << ")\n";

    delete_tree(head);

    head = new TreeNode(20);
    head->left = new TreeNode(-3);
    head->left->right = new TreeNode(2);
    head->left->left = new TreeNode(2);

    result = s.maxPathSum(head);
    cout << "\n(result = " << result << ")\n";

    delete_tree(head);
}
