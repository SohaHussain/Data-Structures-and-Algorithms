// given a sorted and a rotated array of distinct elements and an element x, find if x is present in array or not
// logic: 

#include<bits/stdc++.h>
using namespace std;

int ele(int a[],int l,int h,int x)
{
    if(l>h)
    return -1;

    int m=(l+h)/2;

    // if mid element is the element to be searched
    if(a[m]==x)
    return m;
    
    // if the left part is sorted 
    if(a[l]<=a[m])
    {
        if(x>=a[l] && x<=a[m])
        return ele(a,l,m-1,x);
        return ele(a,m+1,h,x);
    }

    // if the right part is sorted
    if(x>=a[m] && x<=a[h])
    return ele(a,m+1,h,x);

    return ele(a,l,m-1,x);


}
int main()
{
    int n;
    cin>>n;
    int a[n],x;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>x;
    cout<<ele(a,0,n-1,x);
    return 0;
}