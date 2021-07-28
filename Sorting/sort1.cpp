// Bubble sort
// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are 
// in wrong order.

#include<bits/stdc++.h>
using namespace std;

void bubsort(int a[],int n)
{
    bool swapped;
    for(int i=0;i<n-1;i++)
    {
        swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)
        break;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    bubsort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}