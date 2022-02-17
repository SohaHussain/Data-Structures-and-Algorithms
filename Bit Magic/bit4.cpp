// https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/

//logic: a^0 = a and a^a = 0
//       so xor the whole array and at last the element which remains is the unique element as duplicate
//       elements cancel each other
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={2,3,4,1,2,1,3,6,4};
    int ans=arr[0];
    for(int i=1;i<9;i++)
    ans^=arr[i];
    cout<<ans;
    return 0;
}
