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