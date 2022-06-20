// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// recursive

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *newhead = deleteDuplicates(head->next);
        if(head->val == newhead->val)
            return newhead;
        else
        {
            head->next = newhead;
            return head;
        }
        
    }
};

// iterative

ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *t = head;
        while(t->next!=NULL)
        {
            if(t->val == t->next->val)
            {
                ListNode *del = t->next;
                t->next = del->next;
                delete del;
            }
            else
                t= t->next;
        }
        return head;
    }
};
