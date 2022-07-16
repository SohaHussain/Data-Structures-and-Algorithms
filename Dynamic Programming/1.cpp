int knapSack(int w, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
       return solve(w,wt,val,n,dp);
    }
    int solve(int w,int wt[],int val[],int n,vector<vector<int>>&dp)
    {
        if(n==0 || w==0)
        return 0;
        
        if(dp[n][w]!=-1)
        return dp[n][w];
        
        if(wt[n-1]<=w)
        {
            dp[n][w]=max(val[n-1]+solve(w-wt[n-1],wt,val,n-1,dp),
                         solve(w,wt,val,n-1,dp));
                         return dp[n][w];
        }
        
        else if(wt[n-1]>w)
        {
            dp[n][w]=solve(w,wt,val,n-1,dp);
            return dp[n][w];
        }
    }