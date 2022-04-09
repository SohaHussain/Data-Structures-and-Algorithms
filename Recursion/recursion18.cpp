// subsets of string with ascii values

#include<bits/stdc++.h>
using namespace std;

void subseq(string p , string up)
{
    if(up.length()==0)
    {
        cout<<p<<'\n';
        return;
    }
    subseq(p+up[0],up.substr(1,up.length()));
    subseq(p + to_string(up[0]+0),up.substr(1,up.length()));
    subseq(p,up.substr(1,up.length()));

}
int main()
{
    string str="abc";
    string ans="";
   subseq(ans,str);
   return 0;
}
