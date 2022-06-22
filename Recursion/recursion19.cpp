// printing all the subsequences

#include<bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &ans, int arr[], int n)
{
    if(ind == n)
    {
        for(auto i:ans)
        cout<<i;
        cout<<'\n';
        return;
    }
    
    ans.push_back(arr[ind]);
    //take the particular index in subsequence
    solve(ind+1,ans,arr,n);
    ans.pop_back();
    // not take the particular index in subsequence
    solve(ind+1,ans,arr,n);
}
int main()
{
    int arr[]={3,1,2};
    int n=3;
    vector<int>ans;
    solve(0,ans,arr,n);
    return 0;
}
