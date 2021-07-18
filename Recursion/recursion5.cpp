// factorial(tail recursive)

#include<bits/stdc++.h>
using namespace std;
int fact(int n, int val=1)
{
    if(n==0)
    return val ;
    return fact(n-1,n*val);
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}