//Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row 
//that has the maximum number of 1's

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    int r=1;
    int p;
    int f=0;
    for(int i=0;i<m;i++)
    {
        if(a[0][i]==1)
        {
            p=i;
            f=1;
        }
    }
    if(f==0)
    p=1;
    while(p<m && p>=0 && r<n)
    {
        if(a[r][p]==1 && a[r][p-1]==0 )  
        p--;
        else if(a[r][p]==1 && a[r][p-1]==1)
        p-=2;
        else
        r++;
    }
    cout<<"row with max 1s : "<<r<<'\n';
    return 0;
}
