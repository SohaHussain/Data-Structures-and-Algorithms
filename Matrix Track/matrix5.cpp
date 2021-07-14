// printing matrix in snake pattern
// logic: for odd no. of row go L->R (not 0 based index numbering)
//        for even no. of row go R->L


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
        if((i+1)%2!=0)
        {
            for(int j=0;j<c;j++)
            cout<<a[i][j]<<" ";
            //cout<<'\n';
        }
        else
        {
            for(int j=c-1;j>=0;j--)
            cout<<a[i][j]<<" ";
            //cout<<'\n';
        }
    }
    return 0;

}