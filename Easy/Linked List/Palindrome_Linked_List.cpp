#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    private:
    ListNode *size_list(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast)
            slow = slow->next;
        return(slow);
    }
    ListNode *inverted_list(ListNode *head)
    {
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
            return (false);
        if (head->next == nullptr)
            return(true);
        ListNode *half = inverted_list(size_list(head));
        while (head && half)
        {
            if (head->val != half->val)
                return false;
            head = head->next;
            half = half->next;
        }
        return (true);
    }
};