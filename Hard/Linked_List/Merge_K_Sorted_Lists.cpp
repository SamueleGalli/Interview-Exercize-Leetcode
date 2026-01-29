/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []



Constraints:

    * k == lists.length
    * 0 <= k <= 10^4
    * 0 <= lists[i].length <= 500
    * -10^4 <= lists[i][j] <= 10^4
    * lists[i] is sorted in ascending order.
    * The sum of lists[i].length will not exceed 10^4.


*/

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool invalid(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return (true);
        size_t j = 0;
        while (lists[j] == nullptr)
        {
            j++;
            if (j > lists.size() - 1)
                return (true);
        }
        return (false);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        ListNode dummy;
        int val = numeric_limits<int>::max();
        ListNode *current = &dummy;
        size_t pos = 0;
        size_t j;

        if (invalid(lists) == true)
            return (nullptr);
        for (size_t i = 0; 1; i++)
        {
            if (i > lists.size() - 1)
            {
                lists[pos] = lists[pos]->next;
                current->next = new ListNode(val);
                current = current->next;
                j = 0;
                while (lists[j] == nullptr)
                {
                    j++;
                    if (j > lists.size() - 1)
                        return (dummy.next);
                }
                val = lists[j]->val;
                i = 0;
            }
            if (lists[i] && lists[i]->val <= val)
            {
                val = lists[i]->val;
                pos = i;
            }
        }
        return (dummy.next);
    }
};

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

void alloc_list_for_ex(ListNode *&head1, ListNode *&head2, ListNode *&head3)
{
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    head3->next = new ListNode(6);
}

void print_nodes(ListNode *NewNode)
{
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
}

int main()
{
    ListNode *head1 = new ListNode(1);
    ListNode *head2 = new ListNode(1);
    ListNode *head3 = new ListNode(2);
    Solution s;
    vector<ListNode *> vec;
    ListNode *NewNode;

    alloc_list_for_ex(head1, head2, head3);

    vec.push_back(head1);
    vec.push_back(head2);
    vec.push_back(head3);
    cout << "<lista risultante>\n\n";
    NewNode = s.mergeKLists(vec);
    print_nodes(NewNode);
    Delete_lists(NewNode);
    cout << "<lista risultante>\n\n";
    vec = {};
    vec.push_back(nullptr);
    vec.push_back(nullptr);
    vec.push_back(nullptr);
    NewNode = s.mergeKLists(vec);
    print_nodes(NewNode);
    Delete_lists(NewNode);
    Delete_lists(head1);
    Delete_lists(head2);
    Delete_lists(head3);
}