// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

int knapSack(int n, int w, int val[], int wt[])
    {
        int dp[n+1][w+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                //initialization
                if(i==0 || j==0)
                dp[i][j]=0;
                
                else if(wt[i-1]<=j)
                  
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]], // if item is considered it can be considered again therefore we do not do i-1
                             dp[i-1][j]); // if item is not taken it will not be taken again therefor i-1
                
                else if(wt[i-1]>j)
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w];
    }
