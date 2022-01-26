// cycle sort

#include<bits/stdc++.h>
using namespace std;

void cyclesort(vector<int> &a)
{
    int n= a.size();
    int i=0;
    while(i<n)
    {
        int corrind = a[i]-1;
        if(a[i]!=a[corrind])
        swap(a[i],a[corrind]);
        else
        i++;
    }
}
int main()
{
    vector<int> arr={3,5,2,1,4};
    cyclesort(arr);
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    return 0;
}
