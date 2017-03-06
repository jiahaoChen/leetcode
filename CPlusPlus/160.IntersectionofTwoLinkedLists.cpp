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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int countA = 0;
        int countB = 0;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA)
        {
            countA++;
            pA = pA->next;
        }
        
        while (pB)
        {
            countB++;
            pB = pB->next;
        }
        pA = headA;
        pB = headB;
        if (countA > countB)
        {
            int diff = countA - countB;
            for (int i = 0; i < diff; ++i)
            {
                pA = pA->next;
            }
            while (pA)
            {
                if (pA == pB)
                    return pA;
                pA = pA->next;
                pB = pB->next;
            }
            return NULL;
        }
        else if (countB > countA)
        {
            int diff = countB -countA;
            for (int i = 0; i < diff; ++i)
            {
                pB = pB->next;
            }
            while (pB)
            {
                if (pB == pA)
                    return pB;
                pA = pA->next;
                pB = pB->next;
            }
            return NULL;
        }
        else
        {
            while (pA)
            {
                if (pA == pB)
                    return pA;
                pA = pA->next;
                pB = pB->next;
            }
            return NULL;
        }
    }
};