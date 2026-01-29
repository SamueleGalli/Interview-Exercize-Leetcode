/*
Given the head of a linked list, return the list after sorting it in ascending order.



Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []



Constraints:

    * The number of nodes in the list is in the range [0, 5 * 10^4].
    * -10^5 <= Node.val <= 10^5



Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>

using namespace std;

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *middle = head;
        ListNode *end = head;
        ListNode *prev = nullptr;
        ListNode *current_middle;
        ListNode *current_end;
        ListNode dummy;
        ListNode *result = &dummy;
        if (!head)
            return (nullptr);
        if (head && !head->next)
            return (head);
        while (end && end->next)
        {
            prev = middle;
            middle = middle->next;
            end = end->next->next;
        }
        current_end = sortList(middle);
        prev->next = nullptr;
        current_middle = sortList(head);
        while (current_middle && current_end)
        {
            if (current_middle->val > current_end->val)
            {
                result->next = current_end;
                current_end = current_end->next;
            }
            else
            {
                result->next = current_middle;
                current_middle = current_middle->next;
            }
            result = result->next;
        }
        if (current_middle)
            result->next = current_middle;
        if (current_end)
            result->next = current_end;
        return (dummy.next);
    }
};


void print_nodes(ListNode *NewNode)
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
        NewNode = NewNode->next;
    }
    cout << "\n\nfine stampa\n\n";
}

void Delete_lists(ListNode *&head)
{
    ListNode *current = head;
    while (head != nullptr)
    {
        current = head;
        head = head->next;
        delete (current);
    }
}

void alloc_nodes(ListNode *&head)
{
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
}

int main()
{
    ListNode *head = new ListNode(4);
    ListNode *NewNode;
    Solution s;

    alloc_nodes(head);
    print_nodes(head);
    NewNode = s.sortList(head);
    cout << "\n\n(nodo ordinato)\n\n";
    print_nodes(NewNode);
    Delete_lists(NewNode);
    cout << "\n\n(nodo ordinato)\n\n";
    NewNode = s.sortList(nullptr);
    print_nodes(NewNode);
    Delete_lists(NewNode);
}