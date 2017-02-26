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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *fast = head, *slow = head, *pre = head;
        while(fast != NULL && fast->next != NULL)
        {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode* A = sortList(slow);
        ListNode* B = sortList(head);
        return merge(A, B);
    }
    
    ListNode* merge(ListNode* A, ListNode* B) {
        ListNode* ret = new ListNode(0), *p = ret;
        while(A != NULL && B != NULL)
        {
            if (A->val <= B->val) {
                p->next = A;
                A = A->next;
            }
            else {
                p->next = B;
                B = B->next;
            }
            p = p->next;
        }
        if (A != NULL)
            p->next = A;
        if (B != NULL)
            p->next = B;
        return ret->next;
    }
};