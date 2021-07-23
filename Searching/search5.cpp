// count no. of 1s in a sorted binary array

#include<bits/stdc++.h>
using namespace std;

int ones(int a[],int l, int h,int n)
{
    int left=-1;
    if(l<=h)
    {
        int m=l+(h-l)/2;
        if(a[m]==1 && (m==0 || a[m-1]<1))
        left=m;
        
    }
    if(left==-1)
    return 0;
    return n-left;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<ones(a,0,n-1,n);
    return 0;
}