#include<bits/stdc++.h>
using namespace std;

int func(vector<int> n,int target,int i)
{
    if(i==n.size())
    return -1;
    else if(n[i]==target)
    return i;
    else
    return func(n,target,i+1);
}

int main()
{
    vector<int> n(5);
    for(int i=0;i<5;i++)
    cin>>n[i];
    cout<<func(n,5,0);
    return 0;
}
