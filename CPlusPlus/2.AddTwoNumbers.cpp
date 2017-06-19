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
        int carryVal = 0;
        ListNode* newNode = new ListNode(0);
        ListNode* curr = newNode;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carryVal;
            l1->val = sum % 10;
            carryVal = sum / 10;
            curr->next = l1;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
            curr->next = NULL;
        }
        while (l1) {
            int sum = l1->val + carryVal;
            l1->val = sum % 10;
            carryVal = sum / 10;
            curr->next = l1;
            curr = curr->next;
            l1 = l1->next;
            curr->next = NULL;
        }

        while (l2) {
            int sum = l2->val + carryVal;
            l2->val = sum % 10;
            carryVal = sum / 10;
            curr->next = l2;
            curr = curr->next;
            l2 = l2->next;
            curr->next = NULL;
        }
        if (carryVal) {
            curr->next = new ListNode(carryVal);
        }

        return newNode->next;
    }
};