// Selection sort

#include<bits/stdc++.h>
using namespace std;

void selsort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int maxeleindex=0;
        int last = n-i-1;
        for(int j=0;j<=last;j++)
        {
            if(a[j]>=a[maxeleindex])
            maxeleindex=j;     
        }
        swap(a[maxeleindex],a[last]);
    }
    
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    selsort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
