// palindrome

#include<bits/stdc++.h>
using namespace std;
bool palindrome(string str, int e, int s=0)
{
  if(s>e)
  return true;
  if(s==e)
  return true;
  if(str[s]!=str[e])
  return false;
  return(str,s+1,e-1);
}
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    cout<<palindrome(str,n-1);
    return 0;
}