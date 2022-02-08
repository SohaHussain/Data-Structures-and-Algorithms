// https://www.geeksforgeeks.org/find-nth-magic-number/
// TC -> log(n)
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n = 6;
  int base = 5;
  int ans = 0;
  while(n>0)
  {
    int last = n&1;
    n = n>>1;
    ans += last*base;
    base *=5;
  }
  cout<<ans;
  return 0;
}
    
    
