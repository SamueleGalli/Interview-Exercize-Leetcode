#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
    int size_node(ListNode *temp, int index)
    {
        while (temp != nullptr)
        {
            index++;
            temp = temp->next;
        }
        return (index);
    }
    ListNode *value_to_remove(ListNode *head, int i, int n)
    {
        while (i < n && head != nullptr)
        {
            i++;
            head = head->next;
        }
        return (head);
    }

    ListNode *temp_node(ListNode *head, ListNode *remove)
    {
        while (head->next != remove && head != remove)
            head = head->next;
        return (head);
    }
    ListNode *remove_first(ListNode *head)
    {
        ListNode *temp = head->next;
        ListNode *remove = head;
        head = temp;
        delete remove;
        return (head);
    }
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        ListNode *remove = head;
        int i = size_node(temp, 0);
        if (i == 1)
        {
            delete head;
            return (nullptr);
        }
        n = i - n;
        i = 0;
        if (n == 0)
        {
            head = remove_first(head);
            return (head);
        }
        remove = value_to_remove(head, i, n);
        temp = temp_node(head, remove);
        temp->next = remove->next;
        delete remove;
        return head;
    }
};