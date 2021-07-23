// Binary Search
// given a sorted array with repetition , find the right most index of an element

#include<bits/stdc++.h>
using namespace std;

int last(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n-1|| x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid-1), x, n);
        else
            return last(arr, (mid+1),high, x, n);
    }
    return -1;
}
 
int main()
{
    int n;
    cin>>n;
    int a[n],x;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>x;
    cout<<last(a,0,n-1,x,n);
    return 0;
}