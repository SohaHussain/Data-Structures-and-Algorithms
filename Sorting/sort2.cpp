// Selection sort
// In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray 
// is picked and moved to the sorted subarray. 

#include<bits/stdc++.h>
using namespace std;

void selsort(int a[],int n)
{
    int minin;
    for(int i=0;i<n-1;i++)
    {
        minin=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minin])
            minin=j;
        }
        swap(a[i],a[minin]);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    selsort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}