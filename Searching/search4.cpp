// given a sorted array with repetition , find the number of occurences of an element
// logic: find the left most and right most index of the element and then find their difference

#include<bits/stdc++.h>
using namespace std;

int first(int a[],int l,int h,int x)
{
    if(l<=h)
    {
        int m=l+(h-l)/2;
        if(a[m]==x && (m==0 || a[m-1]<x))
        return m;
        else if( x>a[m])
        return first(a,m+1,h,x);
        else
        return first(a,l,m-1,x);
    }
    return -1;
}

int last(int a[],int l,int h,int x,int n)
{
    if(l<=h)
    {
        int m=l+(h-l)/2;
        if(a[m]==x && (m==n-1 || a[m+1]>x))
        return m;
        else if(x<a[m])
        return last(a,l,m-1,x,n);
        else
        return last(a,m+1,h,x,n);
    }
    return -1;
}
int occ(int a[],int l,int h,int x,int n)
{
    int f=first(a,l,h,x);
    int e=last(a,l,h,x,n);
    if (l==-1 || f==-1)
    return 0;
    return (e-f+1);
   
}
int main()
{
    int n;
    cin>>n;
    int a[n],x;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>x;
    cout<<occ(a,0,n-1,x,n);
    return 0;
}