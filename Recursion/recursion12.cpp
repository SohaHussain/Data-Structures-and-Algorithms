#include<bits/stdc++.h>
using namespace std;

int func(vector<int> n,int target,int s,int e)
{
    if(s>e)
    return -1;
    int m=s+(e-s)/2;
    if(n[m]==target)
    return m;
    else if(n[s]<= n[m])
    {
        if(target>=n[s] && target<=n[m])
        return func(n,target,s,m-1);
        else
        return func(n,target,m+1,e);
    }
    else if(target>=n[m] && target<=n[e])
    return func(n,target,m+1,e);
    else
    return func(n,target,s,m-1);
}

int main()
{
    vector<int> n(7);
    for(int i=0;i<7;i++)
    cin>>n[i];
    cout<<func(n,5,0,6);
    return 0;
}
