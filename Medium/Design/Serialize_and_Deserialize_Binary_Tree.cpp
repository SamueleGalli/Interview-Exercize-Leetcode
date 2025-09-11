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