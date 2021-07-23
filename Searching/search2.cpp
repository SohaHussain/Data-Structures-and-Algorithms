// Binary Search
// given a sorted array with repetition , find the left most index of an element

#include<bits/stdc++.h>
using namespace std;

int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
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
    cout<<first(a,0,n-1,x,n);
    return 0;
}