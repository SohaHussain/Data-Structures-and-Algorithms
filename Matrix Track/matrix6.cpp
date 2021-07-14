// transpose of a sqaure matrix
// logic: diagonal elements remain same, only the upper triangle matrix elements are swappped with lower triangle
//         matrix elements
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
       for(int j=i+1;j<c;j++)
       swap(a[i][j],a[j][i]);
   }
   for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       cout<<a[i][j]<<" ";
       cout<<'\n';
   }
   return 0;
}