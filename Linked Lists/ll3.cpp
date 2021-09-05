// insertion at the end of a singly linked list 


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


struct llist
{
    node *head,*tail;
    llist()
    {
        head=NULL;
    }
    void insertbegin(int x)
    {
        node *temp=new node(x);
        temp->next=head;
        head=temp;
    }

    void printlist()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main()
{
    llist ll;
    ll.insertbegin(10);
    ll.insertbegin(20);
    ll.printlist();
    return 0;
}
