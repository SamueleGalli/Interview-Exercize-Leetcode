/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    * The number of nodes in the tree is in the range [0, 2000].
    * -1000 <= Node.val <= 1000


*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <stack>

class Solution
{
private:
    std::vector<std::vector<int>> vector_level(TreeNode *root, std::vector<std::vector<int>> &order)
    {
        int level = 0;
        std::stack<TreeNode *> temp;
        std::stack<int> level_temp;
        level_temp.push(0);
        while (root || !temp.empty())
        {
            if (!root && !temp.empty())
            {
                root = temp.top();
                temp.pop();
                level = level_temp.top();
                level_temp.pop();
                order[level].push_back(root->val);
                level++;
                if (root && root->right)
                {
                    temp.push(root->right);
                    level_temp.push(level);
                }
                root = root->left;
                continue;
            }
            order[level].push_back(root->val);
            level++;
            if (root && root->right)
            {
                temp.push(root->right);
                level_temp.push(level);
            }
            root = root->left;
        }
        return (order);
    }
    int size_tree(TreeNode *root)
    {
        if (!root)
            return (0);
        int left = size_tree(root->left) + 1;
        int right = size_tree(root->right) + 1;
        int total;
        if (left > right)
            total = left;
        else
            total = right;
        return (total);
    }

public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> order;
        if (!root)
            return order;
        order.resize(size_tree(root));
        if (!root->left && !root->right)
        {
            order[0].push_back(root->val);
            return (order);
        }
        return (vector_level(root, order));
    }
};