// find leader in an array
/* leader- an element is called leader if there is no greater element on its right side
   logic: traverse from end and track the max element and keep adding the largest to a stack/vector and then reverse 
          it to get in order*/

#include<bits/stdc++.h>
using namespace std;

void leader(int a[],int n)
{
    vector<int> large;
    int max=a[n-1];
    large.push_back(max);
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>=max)
        {
            max=a[i];
            large.push_back(max);
        }
    }
    for(int i=large.size()-1;i>=0;i--)
    cout<<large[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    leader(a,n);
    return 0;
}