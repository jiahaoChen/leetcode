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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *before = NULL, *after = NULL;
        while (slow) {
            after = slow->next;
            slow->next = before;
            before = slow;
            slow = after;
        }
        slow = before;
        while(head) {
            if (head->val != slow->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};