// find element in a row wise and column wise sorted matrix
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int m[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cin>>m[i][j];
    }
    int x;
    cin>>x;
    int a=0;
    int b=c-1;
    int f=0;
    while(a<r && b>=0)
    {
        if(m[a][b]==x)
        {
            cout<<"row : "<<a+1<<" col : "<<b+1;
            f=1;
            break;
        }
        else if(m[a][b]<x)
        {
            a++;
            continue;
        }
        else if(m[a][b]>x)
        {
            b--;
            continue;
        }
    }
    if(f==0)
    cout<<"not found";
    
    return 0;
}