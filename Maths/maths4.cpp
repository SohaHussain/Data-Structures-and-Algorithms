// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

// gcd/hcf (a,b) = min +ve value of ax+by where x,y are integers

// Euclid's Algo : gcd(a,b)=gcd((rem(b,a),a))

// TC : O(log(max(a,b)))


#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(a==0)
    return b;
    return gcd(b%a,a);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}
