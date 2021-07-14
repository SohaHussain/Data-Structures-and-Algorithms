// rotate a square matrix by 90 degrees counter clockwise
// logic: first find transpose of a matrix and then reverse the columns

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
   //transpose
   for(int i=0;i<r;i++)
   {
       for(int j=i+1;j<c;j++)
       swap(a[i][j],a[j][i]);
   }
   cout<<"after transpose\n";
    for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       cout<<a[i][j]<<" ";
       cout<<endl;

   }
   //reversing columns
   for(int i=0;i<c;i++)
   {
       int low=0;
       int high=r-1;
       while(low<high)
       {
           swap(a[low][i],a[high][i]);
           low++;
           high--;
       }
   }
   cout<<"after reversing\n";
   for(int i=0;i<r;i++)
   {
       for(int j=0;j<c;j++)
       cout<<a[i][j]<<" ";
       cout<<endl;

   }
   return 0;
}