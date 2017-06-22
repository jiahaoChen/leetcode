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
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        // don't use fast->next && fast->next->next, O->O will error
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        ListNode* A = sortList(slow);
        ListNode* B = sortList(head);
        return merge(A, B);

    }

    ListNode* merge(ListNode* A, ListNode* B) {
        ListNode* newNode = new ListNode(0);
        ListNode* currNode = newNode;
        while(A && B) {
            if (A->val <= B->val) {
                currNode->next = A;
                A = A->next;
            } else {
                currNode->next = B;
                B = B->next;
            }
            currNode = currNode->next;
        }
        if (A) {
            currNode->next = A;
        }
        if (B) {
            currNode->next = B;
        }
        return newNode->next;
    }
};