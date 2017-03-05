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
        vector<RandomListNode *> nodeVec;
        RandomListNode* p = head;
        while (p != NULL)
        {
            RandomListNode* node = new RandomListNode(p->label);
            nodeVec.push_back(node);
            p->label = nodeVec.size()-1;
            p = p->next;
        }
        p = head;
        RandomListNode* ret = new RandomListNode(0);
        RandomListNode* pRet = ret; 
        for (int i = 0; i < nodeVec.size(); ++i)
        {
            ret->next = nodeVec[i];
            if (p->random != NULL)
                ret->next->random = nodeVec[p->random->label];
            ret = ret->next;
            cout << ret->label << endl;
            p = p->next;
        }
        p = head;
        for (int i = 0; i < nodeVec.size(); ++i)
        {
            p->label = nodeVec[i]->label;
            p = p->next;
        }
        return pRet->next;
    }
};