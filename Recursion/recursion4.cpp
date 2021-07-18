// print no.s from 1 to n (tail recursive)

#include<bits/stdc++.h>
using namespace std;
void fun(int n,int k=1)
{
    if(n<1)
    return ;
    cout<<k<<" ";
    fun(n-1,k+1);
}
int main()
{
    int n;
    cin>>n;
    fun(n);
    return 0;
}