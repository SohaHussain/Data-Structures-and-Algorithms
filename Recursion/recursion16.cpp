// quick sort
// TC : best case -> O(nlogn)
//      worst case -> O(n*n)

#include<bits/stdc++.h>
using namespace std;

void qsort(vector <int> &arr ,int l, int h) // l and h for figuring which part of array to sort
{
    if(l>=h)
    return;
    // s and e for swapping 
    int s=l;   
    int e=h;
    int m=s+(e-s)/2; // taking mid element as the pivot
    int pivot=arr[m];
    
    while(s<=e)
    {
        while(arr[s]<pivot)
        s++;
        while(arr[e]>pivot)
        e--;

        if(s<=e)
        {
            swap(arr[s],arr[e]);
            s++;
            e--;
        }

        // now pivot is at correct position, sort the remaining two halves
        qsort(arr,l,e);
        qsort(arr,s,h);
    }
}

int main()
{
    vector<int> a={8,3,4,6,5,12};
    qsort(a,0,a.size()-1);
    for(auto i:a)
    cout<<i<<" ";
    return 0;
}
