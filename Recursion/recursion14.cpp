#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &arr,int i,int j,int mxx)
{
    if(i==0)
    return;
    if(j<i)
    {
       if(arr[j]>arr[mxx])
       func(arr,i,j+1,j);
       else
       func(arr,i,j+1,mxx);
    }
    else
    {
        swap(arr[mxx],arr[i-1]);
        func(arr,i-1,0,0);
    }
}
int main()
{
    vector<int> arr={5,3,2,4,1};
    func(arr,arr.size(),0,0);
    for(auto i:arr)
    cout<<i<<" ";
    return 0;
}
