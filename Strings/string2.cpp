// given a string find the 1st repeating character in it(whose 1st index appears 1st)
//logic: make count[256] and then traverse the string and for every character strore its 1st index

#include<bits/stdc++.h>
using namespace std;

int repc(string s)
{
    int result = INT_MAX;
    int count[256]={-1};
    for(int i=0;i<s.length();i++)
    {
        if(count[s[i]]==-1)
        count[s[i]]=i;
        else
        result=min(result,count[s[i]]);
    }
    return result;
}
int main()
{
    string s;
    cin>>s;
    int r=repc(s);
    cout<<r<<":"<<s[r];
    return 0;
}
