//  given an array and sum x , find if there is a subarray with sum equal to x

#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   int prefix_sum[n];
   prefix_sum[0]=a[0];
   for(int i=1;i<n;i++)
   {
       prefix_sum[i]=prefix_sum[i-1]+a[i];
   }
   int x;
   cin>>x;
   unordered_set<int> s;
   for(int i=0;i<n;i++)
   {
       int t=x-prefix_sum[i];
       if(s.find(t)!=s.end())
       {
           cout<<"present";
           break;
       }
       s.insert(prefix_sum[i]);
   }
   return 0;
}
