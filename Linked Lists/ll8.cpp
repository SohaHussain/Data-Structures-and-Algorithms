// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *c = head;
        for(int i=0;i<k;i++)
        {
            if(c == NULL)
                return head;
            c = c->next;
        }
        
        ListNode *curr = head;
        ListNode *p = NULL;
        ListNode *n = NULL;
        
        for(int i=0;i<k;i++)
        {
            n = curr->next;
            curr->next = p;
            p = curr;
            curr = n;
        }
        
        head->next = reverseKGroup(curr,k);
        return p;
    }
};
