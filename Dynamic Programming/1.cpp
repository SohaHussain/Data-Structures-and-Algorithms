// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// memoization

int knapSack(int w, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(w+1,-1)); // initialising vector with -1 values
       return solve(w,wt,val,n,dp);
    }
    int solve(int w,int wt[],int val[],int n,vector<vector<int>>&dp)
    {
        // base condition
        if(n==0 || w==0)
        return 0;
        
        // if the given recursive call is already called before use its stored value
        if(dp[n][w]!=-1)
        return dp[n][w];
        
        
        if(wt[n-1]<=w)
        {                
            dp[n][w]=max(val[n-1]+solve(w-wt[n-1],wt,val,n-1,dp), // taking the given item
                         solve(w,wt,val,n-1,dp)); // not taking the given item
                         return dp[n][w];
        }
        
        else if(wt[n-1]>w)
        {
            dp[n][w]=solve(w,wt,val,n-1,dp); // not taking the given item
            return dp[n][w];
        }
    }
