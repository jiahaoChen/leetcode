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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode* newHead = new ListNode(0);
        ListNode* newCurr = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* newPre = newHead;

        while(curr) {
            next = curr->next;
            newCurr = newHead->next;
            newPre = newHead;
            cout << curr->val << endl;
            while(newCurr && curr->val > newCurr->val) {
                newPre = newCurr;
                newCurr = newCurr->next;
            }
            newPre->next = curr;
            curr->next = newCurr;
            curr = next;
        }
        return newHead->next;
    }
};