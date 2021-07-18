// print no.s from 1 to n (not tail recursive)

#include<bits/stdc++.h>
using namespace std;
void fun(int n)
{
    if(n==0)
    return ;
    fun(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cin>>n;
    fun(n);
    return 0;
}