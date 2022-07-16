// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        bool dp[n+1][sum+1];
        
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                dp[i][j]=true;
                
                else if(i==0)
                dp[i][j]=false;
                
                else if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                
                else if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
        
    }
