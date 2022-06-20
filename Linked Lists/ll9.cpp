// https://leetcode.com/problems/merge-two-sorted-lists/

// recursive approach

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL)
            return list2;
        if(list2==NULL)
            return list1;
        if(list1->val<=list2->val)
        {
            list1->next=(mergeTwoLists(list1->next,list2));
            return list1;
        }
       else
        {
            list2->next=(mergeTwoLists(list1,list2->next));
            return list2;
        }
    }
};

// iterative approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL)
            return list2;
        if(list2==NULL)
            return list1;
        ListNode *ans,*t;
        if(list1->val < list2->val)
        {
            ans = list1;
            t = list1;
            list1 = list1->next;
        }
        else
        {
            ans = list2;
            t = list2;
            list2 = list2->next;
        }
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val < list2->val)
            {
                t->next = list1;
                t = list1;
                list1 = list1->next;
            }
            else
            {
                t->next = list2;
                t = list2;
                list2 = list2->next;
            }
        }
        if(list1!=NULL)
            t->next = list1;
        else
            t->next = list2;
        return ans;
    }
};
