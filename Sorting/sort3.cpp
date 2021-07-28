// Insertion sort
// Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. 
// The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed
// at the correct position in the sorted part.

// Algorithm :
// To sort an array of size n in ascending order: 
// 1: Iterate from arr[1] to arr[n] over the array. 
// 2: Compare the current element (key) to its predecessor. 
// 3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements
//    one position up to make space for the swapped element.

#include<bits/stdc++.h>
using namespace std;

void inssort(int a[],int n)
{
    int key;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        { 
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    inssort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}