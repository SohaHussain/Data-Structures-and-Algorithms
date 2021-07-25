// given a sorted array and a sum , find if there is a triplet with the given sum

#include<bits/stdc++.h>
using namespace std;

bool checkpair(int a[],int l,int r,int x)
{
    while(l<r)
    {
        if(a[l]+a[r]==x)
        return true;
        if(a[l]+a[r]>x)
        r--;
        else
        l++;
    }
    return false;
}
bool triplet(int a[],int n, int s)
{
    for(int i=0;i<n;i++)
    {
       int r= checkpair(a,i+1,n-1,s-a[i]);
       if(r==1)
       {
           return true;

       }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int a[n],s;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>s;
    cout<<triplet(a,n,s);
    return 0;
}