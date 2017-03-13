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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        while(lists.size() > 1)
        {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* A, ListNode* B)
    {
        if (!A)
            return B;
        if (!B)
            return A;
        if (A->val <= B->val)
        {
            A->next = mergeTwoLists(A->next, B);
            return A;
        }
        else
        {
            B->next = mergeTwoLists(A, B->next);
            return B;
        }
            
    }
};