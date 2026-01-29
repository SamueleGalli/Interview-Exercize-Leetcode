
/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.



Example 1:

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]



Constraints:

    * 0 <= n <= 1000
    * -10^4 <= Node.val <= 10^4
    * Node.random is null or is pointing to some node in the linked list.


*/

#include <stdlib.h>
#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// TODO Usare mappe di nodi(nodo originale->valori "nodo reale"->"nodo fittizio")

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *result = new Node(head->val);
        Node *current = result;
        
        while (current)
        {
            
            current = current->next;
        }
        return (result);
    }
};

void print_nodes(Node *NewNode)
{
    cout << "\n\nInizio stampa\n\n";
    if (NewNode == nullptr)
    {
        cout << "lista vuoto\n";
        return;
    }
    while (NewNode != nullptr)
    {
        cout << "NewNode->val = " << NewNode->val << endl;
        cout << "NewNode->random->value = " << NewNode->random->val << endl;
        NewNode = NewNode->next;
    }
    cout << "\n\nfine stampa\n\n";
}

void Delete_lists(Node *&head)
{
    Node *current = head;
    while (head != nullptr)
    {
        current = head;
        head = head->next;
        delete (current);
    }
}

int main()
{
    Node *head;
    Node *node1 = new Node(7);
    Node *node2 = new Node(13);
    Node *node3 = new Node(11);
    Node *node4 = new Node(10);
    Node *node5 = new Node(1);
    Solution s;
    Node *Create_me;

    head = node1;
    node1->random = node2;
    node2->random = node4;
    node3->random = node1;
    node4->random = node5;
    node5->random = node3;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Create_me = s.copyRandomList(head);
    print_nodes(head);
    print_nodes(Create_me);
    Delete_lists(head);
    Delete_lists(Create_me);
}