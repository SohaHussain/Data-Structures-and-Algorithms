// simple linked list with three nodes

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return 0;
}
