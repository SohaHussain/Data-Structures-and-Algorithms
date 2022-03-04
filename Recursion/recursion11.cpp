#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

void func(vector<int> n,int target,int i)
{
    if(i==n.size())
    return ;
    else if(n[i]==target)
    ans.push_back(i);
    func(n,target,i+1);
}

int main()
{
    vector<int> n(5);
    for(int i=0;i<5;i++)
    cin>>n[i];
    func(n,5,0);
    for(auto i:ans)
    cout<<i<<" ";
    return 0;
}
