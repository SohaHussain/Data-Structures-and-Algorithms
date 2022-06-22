// print any one subsequence with the given sum

// to print any subsequence make the function call return true instead of just returning when the base condition is satisfied else return false
// and only make future function calls if the previous function call returns false.

#include<bits/stdc++.h>
using namespace std;

bool solve(int ind, vector<int> &ans, int arr[], int n, int s,int cs)
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
            return true;
        }
        return false;        
    }
    
    ans.push_back(arr[ind]);
    if(solve(ind+1,ans,arr,n,s,cs+arr[ind])==true)
    return true;
    ans.pop_back();
    if(solve(ind+1,ans,arr,n,s,cs)==true)
    return true;
    return false;
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
