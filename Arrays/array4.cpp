// trapping rainwater
/* input is an array representing the height of walls and the output is the amount of water they can trap
   example: a[]={2,0,2}  it can hold 1*2 units of water
   logic: we start from 2nd element take the max on its left and take the max on its right.
          then take the min of both and subtract the current element to get water at ith position
   Algorithm :
        1.Take two pointers l and r. Initialize l to the starting index 0 and r to the last index n-1
        2.Since l is the first element, left_max would be 0, and right max for r would be 0
        3.While l <= r , iterate the array . We have two possible conditions
          
          Condition1 : left_max <= right max
          1.Consider Element at index l
          2.Since we have traversed all elements to the left of l, left_max is known 
          3.For the right max of l, We can say that the right max would  always be >= current r_max here
          4.So, min(left_max,right_max) would always equal to left_max in this case
          5.Increment l
         
          Condition2 : left_max >  right max
          1.Consider Element at index r
          2.Since we have traversed all elements to the right of r, right_max is known
          3.For the left max of l, We can say that the left max would  always be >= current l_max here
          4.So, min(left_max,right_max) would always equal to right_max in this case
          5.Decrement r*/

#include<bits/stdc++.h>
using namespace std;

int water(int a[],int n)
{
    // indices to traverse the array
    int left=0;
    int right=n-1;

    // to store left max and right max
    int lmax=0;
    int rmax=0;

    // to store total amount of rain water trapped
    int result=0;

    while(left<=right)
    {
        // checking for min. of lmax and rmax for each element
        if(rmax<=lmax)
        {
            // adding to result the max of 0 and diff. b/w rmax and current element at right index
            result+=max(0,rmax-a[right]);

            // updating rmax with the max. value at right
            rmax=max(rmax,a[right]);

            // moving right pointer towards previous item
            right-=1;
        }

        else
        {
            // adding to result the max of 0 and diff. b/w lmax and current element at left index
            result+=max(0,lmax-a[left]);

            // updating lmax with max. value at left
            lmax=max(lmax,a[left]);

            // moving left pointer towards next item
            left+=1;
        }
    }
    return result;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<water(a,n);
    return 0;
}
