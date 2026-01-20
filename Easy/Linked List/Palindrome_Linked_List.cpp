/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

 

Constraints:

    * The number of nodes in the list is in the range [1, 10^5].
    * 0 <= Node.val <= 9

 
Follow up: Could you do it in O(n) time and O(1) space?
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