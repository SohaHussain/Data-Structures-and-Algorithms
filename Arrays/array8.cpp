// check if a given array can be divided into 3 parts with equal sum
// eg: {5,2,6,1,1,1,5}
// part1-> 5,2
// part2-> 6,1
// part3-> 1,1,5

#include<bits/stdc++.h>
using namespace std;

void div(int a[],int n)
{
    int prefix_sum[n]={0};
    prefix_sum[0]=a[0];
    for(int i=1;i<n;i++)
    prefix_sum[i]=prefix_sum[i-1]+a[i];
    if(prefix_sum[n-1]%3==0)
    {
        int o=-1;
        int t=-1;
        for(int i=0;i<n-1;i++)
        {
            if(prefix_sum[i]==prefix_sum[n-1]/3)
            o=i;
            else if(prefix_sum[i]==(prefix_sum[n-1]/3)*2)
            t=i;
        }
        if(o!=-1 && t!=-1)
        cout<<"yes";
        else
        cout<<"no";
    }
    else
    cout<<"no";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    div(a,n);
    return 0;
}