// finding median in a row wise sorted matrix
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> m;
    int t;
    for(int i=0;i<r;i++)
    {
        vector<int> row;
        for(int j=0;j<c;j++)
        {
            cin>>t;
            row.push_back(t);
        }
        m.push_back(row);
    }
    
    vector<int> s;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        s.push_back(m[i][j]);
    }
    sort(s.begin(),s.end());
    for(int i=0;i<(r*c);i++)
    cout<<s[i]<<" ";
    cout<<endl;
    int p=((r*c)/2);
    cout<<p;
    cout<<endl;
    cout<<s[p];
    return 0;
}