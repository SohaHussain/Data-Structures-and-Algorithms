// check whether 2 strings are rotations of each other or not
// logic: do s1=s1+s1 , if s2 is present in s1 then they are rotations

#include<bits/stdc++.h>
using namespace std;

bool rotations(string s1, string s2)
{
   if(s1.length()!=s2.length())
   return false;
   s1=s1+s1;
   return(s1.find(s2)!=string::npos);

}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<rotations(s1,s2);
    return 0;
}