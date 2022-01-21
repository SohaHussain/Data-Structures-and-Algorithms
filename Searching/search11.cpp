// order agnostic binary search

#include<bits/stdc++.h>
using namespace std;

int bs(int a[], int t)
{
    int start = 0;
    int end = *(&a+1)-a;
    bool order = a[start]<a[end];

    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(a[mid]== t)
        return mid;
        if(order)
        {
            if(a[mid]>t)
            end = mid - 1;
        
            else 
            start = mid + 1;       
        }
        else
        {
            if(a[mid]<t)
            end = mid - 1;
            else 
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int target = 4;
    int ans = bs(arr,target);
    cout<<ans;
    return 0;
}