// given an infinite sized sorted array and an element x, find if x is present in the array or not
// logic: we check for index 2,4,8,16... if x<a[index] apply binary search
// here infinite array means an array whose bounds are not known

#include<bits/stdc++.h>
using namespace std;

int bs(int a[],int l,int h,int x)
{
    if(l<=h)
    {
        int m=l+(h-l)/2;
        if(a[m]==x)
        return m;
        else if(a[m]<x)
        return bs(a,m+1,h,x);
        else
        return bs(a,l,m-1,x);
    }
    return -1;
}
int pos(int a[],int x)
{
    if(a[0]==x)
    return 0;
    int i=1;
    while(a[i]<x)
    i=i*2;
    if(a[i]==x)
    return i;
    else
    return bs(a,i/2,i,x);
}
int main()
{
    int a[]={1,2,3,4,40,50,56,67,78,102,103,345,567,890};
    int x;
    cin>>x;
    cout<<pos(a,x);
    return 0;
}
