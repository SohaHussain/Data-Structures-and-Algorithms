// https://leetcode.com/problems/coin-change/

int coinChange(vector<int>& coins, int amt) 
    {
        int n=coins.size();
        int dp[n+1][amt+1];
        
        for(int j=1;j<=amt;j++)
            dp[0][j]=INT_MAX-1;
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=1;j<=amt;j++)
        {
            if(j%coins[0] == 0)
                dp[1][j]=j/coins[0];
            else
                dp[1][j]=INT_MAX-1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=amt;j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[n][amt]<=amt)
        return dp[n][amt];
        return -1;
    }

// or with out initialising the 2nd row

int coinChange(vector<int>& coins, int amt) 
    {
        int n=coins.size();
        int dp[n+1][amt+1];
        
        for(int j=1;j<=amt;j++)
            dp[0][j]=INT_MAX-1;
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amt;j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[n][amt]<=amt)
        return dp[n][amt];
        return -1;
    }
