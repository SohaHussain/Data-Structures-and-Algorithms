//find even/odd

//logic: leaving the last bit , ecery bit in binary form is a power of 2, therefore if the last bit is 1 
//       the number will be odd (even+1=odd) otherwise even

// to get the last bit -> (n&1)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=33;
    if((n&1)==0)
    cout<<"even";
    else
    cout<<"odd";
    return 0;
}
