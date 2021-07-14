// rotate a square matrix clockwise
// first find transpose and then reverse the rows

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cin>>a[i][j];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=i+1;j<c;j++)
        swap(a[i][j],a[j][i]);
    }
    for(int i=0;i<r;i++)
    {
        int low=0;
        int high=c-1;
        while(low<high)
        {
          swap(a[i][low],a[i][high]);
          low++;
          high--;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}