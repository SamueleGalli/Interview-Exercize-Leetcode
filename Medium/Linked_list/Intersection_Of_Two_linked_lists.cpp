struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    private:
        ListNode *cicle_list(ListNode *Head, ListNode *pointer)
        {
            while (Head)
            {
                if (Head == pointer)
                    return (pointer);
                Head = Head->next;
            }
            return (nullptr);
        }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp;
        while (headA && headB)
        {
            temp = cicle_list(headB, headA);
            if (temp != nullptr)
                return (temp);
            headA = headA->next;
        }
        return (nullptr);
    }
};