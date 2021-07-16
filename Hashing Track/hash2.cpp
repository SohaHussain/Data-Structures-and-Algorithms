// finding a subarray with sum equal to 0
// logic: calc. prefix sum of all and store it in a hash table and check if the prefix sum has appeared before .
#include<bits/stdc++.h>
using namespace std;

bool check(int a[],int n)
{
    unordered_set<int> us;
    int prefix_sum=0;
       
    for(int i=0;i<n;i++)
    {
      prefix_sum+=a[i];
      if(us.find(prefix_sum)!=us.end())
      return true;
      us.insert(prefix_sum);
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<check(a,n);
    return 0;
}