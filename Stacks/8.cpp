// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

long long trappingWater(int arr[], int n){
        int maxl[n];
        int maxr[n];
        int l=arr[0];
        int r=arr[n-1];
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>l)
            {
                l=arr[i];
                maxl[i]=l;
            }
            else
            {
                maxl[i]=l;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>r)
            {
                r=arr[i];
                maxr[i]=r;
            }
            else
            {
                maxr[i]=r;
            }
        }
        for(int i=0;i<n;i++)
        {
            ans+=(min(maxl[i],maxr[i])-arr[i]);
        }
        return ans;
    }
