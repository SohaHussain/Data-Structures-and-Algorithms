//  given an array and sum x , find if there is a subarray with sum equal to x.

#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   int x;
   cin>>x;
   unordered_set<int> s;
   for(int i=0;i<n;i++)
   {
       int t=x-a[i];
       if(s.find(t)!=s.end())
       {
           cout<<"present";
           break;
       }
       s.insert(a[i]);
   }
   return 0;
}