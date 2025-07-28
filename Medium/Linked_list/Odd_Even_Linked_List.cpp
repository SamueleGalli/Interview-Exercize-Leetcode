struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if (head == nullptr)
            return head;
        int i;
        ListNode *origin;
        ListNode *odd;
        ListNode *even;
        ListNode *tempEven;

        origin = head;
        
        if (origin->next == nullptr)
        return origin;
        
        i = 3;
        odd = head;
        even = origin->next;
        tempEven = even;

        origin = origin->next->next;
        while (origin != nullptr)
        {
            if (i % 2 == 0)
            {
                even->next = origin;
                even = even->next;
            }
            else
            {
                odd->next = origin;
                odd = odd->next;
            }
            origin = origin->next;
            i++;
        }
        even->next = nullptr;
        odd->next = tempEven;
        return (head);
    }
};