// subsequence with a given sum

#include<bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &ans, int arr[], int n, int s,int cs)
{
    if(ind == n)
    {
        if(cs == s)
        {
            if(ans.size()==0)
            cout<<"{}";
            for(auto i:ans)
            cout<<i;
            cout<<'\n';
        }
        return;        
    }
    ans.push_back(arr[ind]);
    solve(ind+1,ans,arr,n,s,cs+arr[ind]);
    ans.pop_back();
    solve(ind+1,ans,arr,n,s,cs);
}
int main()
{
    int arr[]={3,1,2};
    int n=3;
    int sum = 3;
    vector<int>ans;
    solve(0,ans,arr,n,sum,0);
    return 0;
}
