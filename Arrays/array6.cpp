// maximum sum of k consecutive elements
/* logic: sliding window technique:
          1. compute sum of first k elements using linear loop and store it in a variable
          2. graze linearly over array till end and keep track of max. sum
          3. to get current window sum, subtract first element from previous window and add last element of current
          window */

#include<bits/stdc++.h>
using namespace std;

int maxsum(int a[],int n,int k)
{
    int result=0;
    int msum=0;
    for(int i=0;i<k;i++)
    msum+=a[i];
    result=msum;
    for(int i=k;i<n;i++)
    {
        // current window sum
        msum=msum-a[i-k]+a[i];
        result=max(result,msum);
    }
    return result;
}
int main()        
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;
    cout<<maxsum(a,n,k);
    return 0;
}