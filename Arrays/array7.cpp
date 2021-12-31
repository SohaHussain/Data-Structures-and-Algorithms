// find if the given array has an equilibrium point
/* equilibrium point-> sum of elements before= sum of elements after
   logic: prefix sum:
          1. first calculate the sum of whole array
          2. iterate through the array and check if the sum of elements left to the current element is equal to 
             sum - current element , if not add current element to left sum and subtract current element from the sum
             of array
   */

#include<bits/stdc++.h>
using namespace std;

bool eqpt(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    int lsum=0;
    for(int i=0;i<n;i++)
    {
        if(lsum==sum-a[i])
        return true;
        lsum+=a[i];
        sum-=a[i];
    }
    return false;
}
int main()  
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<eqpt(a,n);
    return 0;
}
