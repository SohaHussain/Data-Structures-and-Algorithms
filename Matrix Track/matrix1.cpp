// spiral traversal on matrix
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <vector<int>> m; // creating 2d vector
    int r;
    cin>>r;
    int c;
    cin>>c;
    int temp;
    for(int i=0;i<r;i++)
    {
        vector<int> row;
        for(int j=0;j<c;j++)
        {
          cin>>temp;
          row.push_back(temp);
        }
        m.push_back(row);
    }
    
    /*In the below code we are using iterator to access the vector elements.
    1. We are getting vect1D vectors of type vector<int> from the 2D vector m.
    2. We are getting int elements to x from the vector<int> vect 1D vector.
    */

    for (vector<int> vect1D : m)
    {
        for (int x : vect1D)
        {
            cout << x << " ";
        }   
        cout << endl;
    }

    int p,n,k,l;
    k=0; // starting row index
    l=0; // starting column index
    p=m.size(); //ending row index
    n=m[0].size(); //ending column index
    while(k<p && l<n)
    {
       // printing first row from remaining rows
       for(int i=k ; i<p;i++)
       {
         cout<<m[k][i]<<" ";
       }
       k++;

       // printing last column of remaining columns
       for(int i=k;i<p;i++)
       {
           cout<<m[i][n-1]<<" ";
       }
       n--;
       // printing last row from remaining rows
       if(k<p)
       {
           for(int i=n-1;i>=l;i--)
           {
               cout<<m[p-1][i]<<" ";
           }
           p--;
       }
       // printing first column from remaining columns
       if(l<n)
       {
           for(int i=p-1;i>=k;i--)
           {
               cout<<m[i][l]<<" ";
           }
           l++;
       }
    }

    return 0;
}
