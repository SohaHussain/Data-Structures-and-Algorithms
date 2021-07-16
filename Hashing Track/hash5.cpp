// given an unsorted array and a no. x find if there is a pair with sum equal to x
// logic: we insert every item in a hash table and before inserting we check if x-a[i] is already present

#include<bits/stdc++.h>
using namespace std;

bool checkpair(int a[],int n,int x)
{
    unordered_set<int> us;
    for(int i=0;i<n;i++)
    {
        if(us.find(x-a[i])!=us.end())
        return true;
        us.insert(a[i]);
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
    int x;
    cin>>x;
    cout<<checkpair(a,n,x);
    return 0;
}