// given a binary array, find the length of the largest subarray with equal zeroes and ones
// logic: consider every 0 as -1
/* Algorithm:

1. Let input array be arr[] of size n and max_size be the size of output sub-array.

2. Create a temporary array sumleft[] of size n. Store the sum of all elements from arr[0] to arr[i] in sumleft[i].

3. There are two cases, the output sub-array may start from 0th index or may start from some other index. We will return the max of the values obtained by two cases.

4. To find the maximum length sub-array starting from 0th index, scan the sumleft[] and find the maximum i where sumleft[i] = 0.

5. Now, we need to find the subarray where subarray sum is 0 and start index is not 0. This problem is equivalent to finding two indexes i & j in sumleft[] such that 
   sumleft[i] = sumleft[j] and j-i is maximum. To solve this, we create a hash table with size = max-min+1 where min is the minimum value in the sumleft[] and max is the
   maximum value in the sumleft[]. Hash the leftmost occurrences of all different values in sumleft[]. The size of hash is chosen as max-min+1 because there can be these 
   many different possible values in sumleft[]. Initialize all values in hash as -1.

6. To fill and use hash[], traverse sumleft[] from 0 to n-1. If a value is not present in hash[], then store its index in hash. If the value is present, then calculate 
   the difference of current index of sumleft[] and previously stored value in hash[]. If this difference is more than maxsize, then update the maxsize.

7. To handle corner cases (all 1s and all 0s), we initialize maxsize as -1. If the maxsize remains -1, then print there is no such subarray.*/

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
