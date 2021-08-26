// insertion of node at the beginning 

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

void printlist(node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

void push(node **head_ref, int newdata)
{
    node * newnode = new node();
    newnode->data=newdata;
    newnode->next=*head_ref;
    *head_ref=newnode;
}

int main()
{
    node *head = NULL;
    push(&head,1);
    push(&head,2);
    printlist(head);
    return 0;
}