// Binary Search
// given a sorted array and an element x to be searched , find if the element is present in the array or not.
// if not present return -1
#include<bits/stdc++.h>
using namespace std;

int  bs(int a[],int l,int h,int x)
{   
    // base case
    if(l>h)
    return -1;

    int m=l+(h-l)/2; // better way to find middle index to avoid overflow

    if(a[m]==x)
    return m;

    if(a[m]>x)
    return bs(a,0,m-1,x);

    if(a[m]<x)
    return bs(a,m+1,h,x);
}
int main()
{
    int n;
    cin>>n;
    int a[n],x;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>x;
    cout<<bs(a,0,n,x);
    return 0;
}