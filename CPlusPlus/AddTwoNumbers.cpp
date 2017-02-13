/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // space only O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lt1 = l1;
        ListNode* lt2 = l2;
        int one = 0;
        int sum = 0;
        
        
        while(lt1->next != NULL && lt2->next != NULL)
        {
            sum = lt1->val + lt2->val + one;
            lt1->val = lt2->val = sum % 10;
            one = sum / 10;
            lt1 = lt1->next;
            lt2 = lt2->next;
        }
        
        sum = lt1->val + lt2->val + one;
        lt1->val = lt2->val = sum % 10;
        one = sum / 10;
        if (lt1->next == NULL && lt2->next == NULL)
        {
            if (one)
                lt1->next = new ListNode(one);
            return l1;
        }
        
        if (lt2->next == NULL)
        {
            while(lt1->next != NULL)
            {
                lt1 = lt1->next;
                if (one)
                {
                    sum = lt1->val + one;
                    lt1->val = sum % 10;
                    one = sum / 10;
                }
            }
            if (one)
            {
                lt1->next = new ListNode(one);
            }
            return l1;
        }
        else
        {
            while(lt2->next != NULL)
            {
                lt2 = lt2->next;
                if (one)
                {
                    sum = lt2->val + one;
                    lt2->val = sum % 10;
                    one = sum / 10;
                }
            }
            if (one)
            {
                lt2->next = new ListNode(one);
            }
            return l2;
        }

    }
};