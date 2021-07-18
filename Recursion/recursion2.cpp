// print no.s from n to 1 (tail recursive)

#include<bits/stdc++.h>
using namespace std;

void fun(int n)
{
    if(n==0)
    return ;
    cout<<n<<" ";
    fun(n-1);
}
int main()
{
    int n;
    cin>>n;
    fun(n);
    return 0;
}