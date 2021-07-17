// find lexicographic rank of the string
// lexicographic rank- if we consider all permutations of the string and sort them at what position the string appears
// logic: for every character we count how many characters are smaller than this and can take its place
// example- S T R I N G
//          S _ _ _ _ _-> R,I,N,G are smaller so permutations= 4 * 5! +
//          S T _ _ _ _-> R,I,N,G are smaller so permutations= 4 * 4! +
//          S T R _ _ _-> I,N,G are smaller so permutations = 3 * 3! +
//          S T R I _ _-> G is smaller so permutations = 1 * 2! +
//          S T R I N _-> G is smaller so permutations = 1 * 1! +
// at the end add 1 for rank

#include<bits/stdc++.h>
using namespace std;

// Function to print rank of string
// using next_permute()
int lexirank(string str)
{
    // store original string
    string orgStr = str;
  
    // Sort the string in lexicographically
    // ascending order
    sort(str.begin(), str.end());
   
    // Keep iterating until
    // we reach equality condition
    long int i = 1;
    do {
        // check for nth iteration
        if (str == orgStr)
            break;
   
        i++;
    } while (next_permutation(str.begin(), str.end()));
   
    // return iterator value
    return i;
}

int main()
{
    string s;
    cin>>s;
    cout<<lexirank(s);
    return 0;
}