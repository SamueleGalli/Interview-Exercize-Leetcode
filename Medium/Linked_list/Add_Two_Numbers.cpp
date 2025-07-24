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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int num = 0;
        int rest = 0;
        ListNode *Dummyhead = new ListNode(0);
        ListNode *result = Dummyhead;
        while (l1 && l2)
        {
            num = l1->val + l2->val + rest;
            rest = 0;
            rest = num / 10;
            num = num % 10;
            result->next = new ListNode(num);
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            num = l1->val + rest;
            rest = 0;
            rest = num / 10;
            num = num % 10;
            result->next = new ListNode(num);
            result = result->next;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            while (l2)
            {
                num = l2->val + rest;
                rest = 0;
                rest = num / 10;
                num = num % 10;
                result->next = new ListNode(num);
                result = result->next;
                l2 = l2->next;
            }
        }
        if (rest > 0)
            result->next = new ListNode(rest);
        result = Dummyhead->next;
        delete Dummyhead;
        return (result);
    }
};