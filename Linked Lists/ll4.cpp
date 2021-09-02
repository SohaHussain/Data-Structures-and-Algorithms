// recursive traversal in a linked list 

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
   node *head = new node(10);
   head->next=new node(20);
   head->next->next=new node(30);
   head->next->next->next=new node(40);
   printlist(head);
   return 0;
}