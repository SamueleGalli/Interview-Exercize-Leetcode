#include <vector>


class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root || (root && root->left == nullptr && root->right == nullptr))
            return (root);
        Node *current = root;
        Node *start_level = root;
        while (start_level)
        {
            current = start_level;
            while (current)
            {
                if (current->right == nullptr && current->left == nullptr)
                {
                    current = current->next;
                    continue;
                }
                current->left->next = current->right;
                if (current->next)
                    current->right->next = current->next->left;
                current = current->next;
            }
            start_level = start_level->left;
        }
        return (root);
    }
};
