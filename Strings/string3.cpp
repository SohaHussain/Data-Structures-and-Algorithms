// given a string, find the first non repeating character
// logic: make a pair and store the index and count of every character
//        now traverse through array and find character whose first is 1 and second is min

#include<bits/stdc++.h>
using namespace std;
int nonrep(string s)
{
    pair <int,int> arr[256];
    for(int i=0;i<s.length();i++)
    {
       arr[s[i]].first++;
       arr[s[i]].second=i;
    }
    int m=256;
    for(int i=0;i<256;i++)
    {
      if(arr[i].first==1 && arr[i].second<m)
      {
        m=arr[i].second;
      }
    }
    return m;
}
int main()
{
    string s;
    cin>>s;
    int r=nonrep(s);
    cout<<r<<":"<<s[r];
    return 0;
}