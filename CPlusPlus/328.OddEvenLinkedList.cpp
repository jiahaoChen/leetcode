/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;
        
        ListNode *head2 = head->next, *odd = head, *even = head2;
        
        while (true)
        {
            if (!even->next)
            {
                odd->next = NULL;
                break;
            }
            odd->next = even->next;
            odd = odd->next;
            if(!odd->next)
            {
                even->next = NULL;
                break;
            }
            even->next = odd->next;
            even = even->next;
        }
        odd->next = head2;
        return head;
    }
};