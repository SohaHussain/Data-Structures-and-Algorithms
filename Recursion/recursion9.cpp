// given a rope of length n you need to find max. no. of pieces you can make such that length of every piece is
// in set {a,b,c} for given values of a,b,c. if not possible print -1

#include<bits/stdc++.h>
using namespace std;
int maxcuts(int n,int a,int b,int c)
{
    if(n==0)
    return 0;
    if(n<0)
    return -1;
    int res= max(maxcuts(n-a,a,b,c),maxcuts(n-b,a,b,c));
    res=max(maxcuts(n-c,a,b,c),res);
    return res+1;
}
int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cout<<maxcuts(n,a,b,c);
    return 0;
}