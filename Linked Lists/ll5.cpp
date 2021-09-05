// deleting first node of a singly linked list


#include<bits/stdc++.h>
using namespace std;

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

node *delhead(node *head)
{
    if(head==NULL)
    return NULL;
    else
    {
        node *temp=head->next;
        delete head;
        return temp;
    }
}

int main()
{
   node *head = NULL;
   head = insertbegin(head,10);
   head = insertbegin(head,20);
   head = delhead(head);
   printlist(head);
   return 0;
}