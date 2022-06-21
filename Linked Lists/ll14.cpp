// https://leetcode.com/problems/intersection-of-two-linked-lists/

// using unordered sets

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
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        unordered_set<ListNode*> s;
        while(p1!=NULL)
        {
           s.insert(p1);
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            if(s.find(p2)!=s.end())
                return p2;
            else
                p2 = p2->next;
        }
        return NULL;
    }
};

// by equating the lengths of both the lists

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        int n1 = 0;
        int n2 = 0;
        while(p1!=NULL)
        {
            n1++;
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            n2++;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        if(n1>n2)
        {
            int diff = n1-n2;
            while(diff--)
            {
                p1 = p1->next;
            }
        }
        else if(n2>n1)
        {
            int diff = n2-n1;
            while(diff--)
            {
                p2 = p2->next;
            }
        }
        while(p1!=NULL)
        {
            if(p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};

// traversing both lists for n+m length

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while(p1 != p2)
        {
            if(p1 == NULL)
                p1 = headB;
            else
                p1 = p1->next;
            
            if(p2 == NULL)
                p2 = headA;
            else
                p2 = p2->next;
        }
        return p1;
    }
};
