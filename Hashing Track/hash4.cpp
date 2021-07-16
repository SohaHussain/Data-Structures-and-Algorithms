// given a binary array, find the length of the largest subarray with equal zeroes and ones
// logic: consider every 0 as -1

#include<bits/stdc++.h>
using namespace std;

int lsub(int arr[],int n)
{
    // create empty hash map
    unordered_map<int,int> hm;

    int sum = 0; // Initialize sum of elements
    int max_len = 0; // Initialize result
    int ending_index = -1;

    // change 0 to -1
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;
    
    // Traverse through the given array
 
    for (int i = 0; i < n; i++) {
        // Add current element to sum
 
        sum += arr[i];
 
        // To handle sum=0 at last index
 
        if (sum == 0) {
            max_len = i + 1;
            ending_index = i;
        }
 
        // If this sum is seen before, then update max_len
        // if required
 
        if (hm.find(sum) != hm.end()) {
            if (max_len < i - hm[sum]) {
                max_len = i - hm[sum];
                ending_index = i;
                 }
        }
        else // Else put this sum in hash table
            hm[sum] = i;
    }
 
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == -1) ? 0 : 1;
 
    printf("%d to %d\n",
           ending_index - max_len + 1, ending_index);
 
    return max_len;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<lsub(a,n);
    return 0;
}