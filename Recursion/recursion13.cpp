#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &arr,int i,int j)
{
    if(i==0)
    return;
    if(j<i)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
        func(arr,i,j+1);
    }
    else
    func(arr,i-1,0);
}
int main()
{
    vector<int> arr={5,3,2,4,1};
    func(arr,arr.size()-1,0);
    for(auto i:arr)
    cout<<i<<" ";
    return 0;
}
