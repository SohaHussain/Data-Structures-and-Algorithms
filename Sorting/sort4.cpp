// merge sort
// Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the 
// two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. 
// The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges 
// the two sorted sub-arrays into one. 

#include<bits/stdc++.h>
using namespace std;

// merges 2 subarrays

void merge(int a[],int l, int m,int h)
{
    // no. of elements in subarray 1 and 2
     int subarr1 = m-l+1;
     int subarr2 = h-m;

    // temp arrays
    int temp1[subarr1] ;
    int temp2[subarr2];

    // copying elements in temp arrays
    for(int i=0;i<subarr1;i++)
    temp1[i]=a[l+i];
    for(int i=0;i<subarr2;i++)
    temp2[i]=a[m+1+i];

    int i1=0; // initial index of temp1
    int i2=0; // initial index of temp2
    int mi=l; // initial index of merged array

    while(i1<subarr1 && i2<subarr2)
    {
        if(temp1[i1]<=temp2[i2])
        {
            a[mi]=temp1[i1];
            i1++;
        }
        else
        {
            a[mi]=temp2[i2];
            i2++;
        }
        mi++;
    }

    // copying remaining lements of temp1 , if any left
    while(i1<subarr1)
    {
        a[mi]=temp1[i1];
        mi++;
        i1++;
    }

    // copying remaining elements of temp2 , if any left
    while(i2<subarr2)
    {
        a[mi]=temp2[i2];
        mi++;
        i2++;
    }
}
void mergesort(int a[],int l,int h)
{
    if(l>=h)
    return ;
    int m=(l+h)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,h);
    merge(a,l,m,h);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}