// Quick sort

// The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as 
// pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put 
// all greater elements (greater than x) after x. All this should be done in linear time.

#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int h)
{
    int pivot = a[h]; // taking last element as the pivot
    int i=l-1; // index of smaller element

    for(int j=l;j<=h-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return i+1;

}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int p=partition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}