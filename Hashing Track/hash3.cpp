// finding the most frequent element in an array
// logic: inseet all items in a map and then traverse map to find the max. value item

#include<bits/stdc++.h>
using namespace std;

int mostfreq(int a[],int n)
{
    unordered_map<int,int> um;
    for(int i=0;i<n;i++)
    {
        um[a[i]]++;
    }
    int maxc=0;
    int result=-1;
    for(auto i:um)
    {
        if(maxc<i.second)
        {
            result=i.first;
            maxc=i.second;
        }
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    cout<<mostfreq(a,n);
    return 0;
}