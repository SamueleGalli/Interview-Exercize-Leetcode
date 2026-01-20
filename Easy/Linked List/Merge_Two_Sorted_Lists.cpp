/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

 

Constraints:

    * The number of nodes in both lists is in the range [0, 50].
    * -100 <= Node.val <= 100
    * Both list1 and list2 are sorted in non-decreasing order.


*/
#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    private:
    int swap_min_max(int value, ListNode *node)
    {
        int min = node->val;
        ListNode *min_pos = nullptr;
        while (node)
        {
            if (node->val < min)
            {
                min = node->val;
                min_pos = node;
            }
            node = node->next;
        }
        if (min_pos != nullptr)
            min_pos->val = value;
        return(min);
    }
    void swap_value(ListNode *temp, ListNode *merged)
    {
        while (temp)
        {
            merged->val = swap_min_max(merged->val, merged);
            merged = merged->next;
            temp = temp->next;
        }
    }
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 && !list2)
            return (nullptr);
        ListNode *current = nullptr;
        ListNode *other = nullptr;
        if (list1 != nullptr)
        {
            current = list1;
            other = list2;
        }
        else
        {
            current = list2;
            other = list1;
        }
        ListNode *merged = new ListNode(current->val);
        ListNode *head = merged;
        current = current->next;
        while (current)
        {
            merged->next = new ListNode(current->val);
            merged = merged->next;
            current = current->next;
        }
        while (other)
        {
            merged->next = new ListNode(other->val);
            merged = merged->next;
            other = other->next;
        }
        merged = head;
        ListNode *temp = merged;
        swap_value(temp, merged);
        return (head);
    }
};