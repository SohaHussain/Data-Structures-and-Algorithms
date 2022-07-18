// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

vector<int> subset(int n,int arr[],int s,vector<int>&ans)
    {
        bool dp[n+1][s+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(j==0)
                dp[i][j]= true;
                
                else if(i==0)
                dp[i][j]=false;
                
                else if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                
                else if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            }
        }
        for(int i=0;i<=s/2;i++)
        {
            if(dp[n][i]==true)
            ans.push_back(i);
        }
        return ans;
    }
	int minDifference(int arr[], int n)
	{
	    vector<int> ans;
	    int s=0;
	    for(int i=0;i<n;i++)
	    s+=arr[i];
	    subset(n,arr,s,ans);
	 
	    int minn=INT_MAX;
	    for(int i=0;i<ans.size();i++)
	    minn=min(minn,(s-(2*ans[i])));
	    return minn;
	} 
