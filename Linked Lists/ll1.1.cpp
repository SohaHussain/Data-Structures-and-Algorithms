// simple linked list using structure

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

int main()
{
   node *head = new node(10);
   node *temp1 = new node(20);
   node *temp2 = new node(30);
   head -> next = temp1;
   temp1 -> next = temp2;
   return 0;
}