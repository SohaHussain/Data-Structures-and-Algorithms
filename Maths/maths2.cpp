//https://www.geeksforgeeks.org/program-for-newton-raphson-method/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // number whose root is to be calculated
    double n; 
    cin>>n;
    // our guessed root
    double x=n; 
    double root;
    while(true)
    {
        root = 0.5 * (x + (n/x));
        if(abs(root-x)<0.5) // here 0.5 is taken as precision value
        break;
        else
        x=root;
    }
    cout<<root;
    return 0;
}
