// stocks- buy, sell
// input- an array of stock prices on each day
// output- maximum profit
// we are allowed to buy  and sell multiple times

#include<bits/stdc++.h>
using namespace std;

int profit(int a[],int n)
{
    if(n==1)
    return 0;
    int i=0;
    int profit=0;
    while(i<n-1)
    {
        // local minimum
        while((i<n-1)&& (a[i+1]<=a[i]))
        i++;
        if(i==n-1)
        break;
        int buy=i++;

        // local maximum 
        while((i<n)&&(a[i]>=a[i-1]))
        i++;
        int sell=i-1;

        // updating profit 
        profit+=a[sell]-a[buy];

    }
    return profit;
    
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<profit(a,n);
    return 0;
}
