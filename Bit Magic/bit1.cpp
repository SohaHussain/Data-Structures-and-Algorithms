// count set bits in an integer
// Brian Karnigham algo o(no. of set bits)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int r=0;
    while(n>0)
    {
      n=(n&(n-1));
      r++;
    }
    cout<<r;
    return 0;
}