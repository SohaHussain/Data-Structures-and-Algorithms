// https://www.geeksforgeeks.org/sieve-of-eratosthenes/

// TC : O(N * log(log(N)))
// SC : O(N)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=40;
    bool primes[n+1];
    memset(primes,true,sizeof(primes));
    for(int i=2;i*i<=n;i++)
    {
        if(primes[i])
        {
            for(int j=i*2;j<=n;j+=i)
            primes[j]=false;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(primes[i])
        cout<<i<<" ";
    }
    return 0;
}
