// merge sort
// TC : O(nlogn)

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;

    int l[n1];
    int m[n2];

    // dividing and copying original array into two new arrays
    for(int i=0;i<n1;i++)
    l[i]=arr[p+i];
    for(int i=0;i<n2;i++)
    m[i]=arr[q+1+i];

    // using two pointers two merge the sorted arrays
    int i=0,j=0,k=p;
    while(i<n1 && j<n2)
    {
        if(l[i]<=m[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=m[j];
            j++;
        }
        k++;
    }
 
    // if elements are left in 1st array 
    while(i<n1)
    {
        arr[k]=l[i];
        i++;
        k++;
    }

    // if elements are left in second array
    while(j<n2)
    {
        arr[k]=m[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &arr,int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{
    vector<int> a={8,3,4,6,5,12};
    mergesort(a,0,a.size()-1);
    for(auto i:a)
    cout<<i<<" ";
    return 0;
}
