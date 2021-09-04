// insertion at the beginning of a singly linked list 
// t -> O(1)


#include<bits/stdc++.h>
using namespace std;

// self referential structure used because every node has to have the address of the next node and data type of next node
// is same as the current node

struct node{
    int data;
    node *next;
    node(int x)  // constructor
    {
        data=x;
        next=NULL;
    }
};


node *insertbegin(node *head, int x)
{
    node *temp = new node(x);
    temp->next=head;
    return temp;

}
void printlist(node *head)
{
    node *curr=head;
    if(curr==NULL)
    return;
    cout<<curr->data<<" ";
    printlist(curr->next);
}

int main()
{
   node *head = NULL;
   head = insertbegin(head,10);
   head = insertbegin(head,20);
   printlist(head);
   return 0;
}
