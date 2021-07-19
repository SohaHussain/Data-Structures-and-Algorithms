// reverse an array

#include<bits/stdc++.h>
using namespace std;
void rev(int a[],int n)
{
    int l=0;
    int h=n-1;
    while(l<h)
    {
        swap(a[l],a[h]);
        l++;
        h--;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    rev(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}