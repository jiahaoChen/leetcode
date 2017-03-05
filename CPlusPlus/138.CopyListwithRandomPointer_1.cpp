/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* l1;
        RandomListNode* l2;
        if (head == NULL) return NULL;
        for (l1 = head; l1 != NULL; l1 = l1->next)
        {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->random;
            l1->random = l2;
        }
        RandomListNode* newHead = head->random;
        for (l1 = head; l1 != NULL; l1 = l1->next)
        {
            l2 = l1->random;
            l2->random = l2->next?l2->next->random: NULL;
        }
        for (l1 = head; l1 != NULL; l1 = l1->next)
        {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next?l1->next->random: NULL;
        }
        
        return newHead;
    }
};