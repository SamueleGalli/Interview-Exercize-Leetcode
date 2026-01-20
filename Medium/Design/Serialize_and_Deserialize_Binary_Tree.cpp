/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []

 

Constraints:

    * The number of nodes in the tree is in the range [0, 10^4].
    * -1000 <= Node.val <= 1000


*/
#include <iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
private:
    void follow_tree(TreeNode *root, std::string &ser)
    {
        if (root == nullptr)
        {
            ser += "N,";
            return;
        }
        ser += std::to_string(root->val) + ',';
        follow_tree(root->left, ser);
        follow_tree(root->right, ser);
    }
    int convert_data(std::string data, size_t &i)
    {
        int value = 0;
        int sing = +1;
        if (data[i] == '-')
        {
            sing = -1;
            i++;
        }
        while (i < data.size() && data[i] != ',')
        {
            value *= 10;
            value += data[i] - '0';
            i++;
        }
        i++;
        return (value * sing);
    }
    void create_nodes(std::string data, TreeNode *&head, size_t &i)
    {
        if (i > data.size())
            return;
        if (data[i] != 'N')
            head = new TreeNode(convert_data(data, i));
        else
        {
            head = nullptr;
            i += 2;
            return;
        }
        create_nodes(data, head->left, i);
        create_nodes(data, head->right, i);
    }

public:
    std::string serialize(TreeNode *root)
    {
        std::string serialization;
        follow_tree(root, serialization);
        serialization.pop_back();
        return (serialization);
    }

    TreeNode *deserialize(std::string data)
    {
        TreeNode *head = nullptr;
        size_t i = 0;
        create_nodes(data, head, i);
        return head;
    }
};