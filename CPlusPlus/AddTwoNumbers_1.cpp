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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int one = 0;
        ListNode* ret, *point;
        ret = point = new ListNode(0);
        
        while (l1 != NULL || l2 != NULL || one != 0)
        {
            point->next = new ListNode(0);
            point = point->next;
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + one;
            point->val = sum % 10;
            one = sum / 10;
            if (l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        return ret->next;
    }
};