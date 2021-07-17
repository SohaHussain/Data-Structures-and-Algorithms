// we are given 2 strings a text and pattern and we have to check if any permutation of pattern is present in text
// logic: create 2 count[256] arrays , one for pattern and one for 1st window of text. then compare both the arrays
//        if different we slide the window in text string and then decrease the count of previous character and 
//        increase the count of next character and then compare again

#include<bits/stdc++.h>
using namespace std;

bool aresame(char a1[],char a2[])
{
   for(int i=0;i<256;i++)
   {
       if(a1[i]!=a2[i])
       return false;
   }
   return true;
}
void anagram(string txt,string pat)
{
    char counttxtw[256]={0}; // array for text window
    char countpat[256]={0};  // array for pattern 
    
    // counting occurences of each character in pattern and first window of text
    for(int i=0;i<pat.length();i++)
    {
        counttxtw[txt[i]]++;
        countpat[pat[i]]++;
    }
    
    // comparing the current window of text and pattern and upgrading the counttxtw array if not same
    for(int i=pat.length();i<txt.length();i++)
    {
        if(aresame(counttxtw,countpat))
        cout<<"found at index: "<<(i-pat.length())<<'\n';

        //upgrading counttxtw array
        counttxtw[txt[i]]++;
        counttxtw[txt[i-pat.length()]]--;

    }
    // check for last window
    if(aresame(counttxtw,countpat))
    cout<<"found at index: "<<( txt.length()-pat.length());
    
}
int main()
{
    string txt,pat;
    cin>>txt>>pat;
    anagram(txt,pat);
    return 0;
}