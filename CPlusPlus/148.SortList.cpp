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
        if (!head)
            return NULL;
        ListNode* swapNode = head;
        ListNode* currNode = head;
        ListNode* minNode = head;
        bool chage = false;
        while (swapNode)
        {
            currNode = swapNode->next;
            while(currNode)
            {
                if (currNode->val < minNode->val)
                {
                    minNode = currNode;
                    chage = true;
                }
                currNode = currNode->next;
            }
            if (chage)
            {
                int tmp = minNode->val;
                minNode->val = swapNode->val;
                swapNode->val = tmp;    
            }
            chage = false;
            swapNode = swapNode->next;
            minNode = swapNode;
        }
        return head;
    }
};