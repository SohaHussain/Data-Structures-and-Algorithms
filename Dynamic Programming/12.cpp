// https://leetcode.com/problems/longest-common-subsequence/

// recursive (TLE)

int solve(string a,string b,int n,int m)
    {
        if(n==0 || m==0)
            return 0;
        else if(a[n-1]==b[m-1])
            return 1+solve(a,b,n-1,m-1);
        else
            return max(solve(a,b,n-1,m),solve(a,b,n,m-1));
    }
int longestCommonSubsequence(string text1, string text2) 
    {
        int n,m;
        n=text1.length();
        m=text2.length();    
        return solve(text1,text2,n,m);     
    }

// memoization (bottom up)
int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(text1,text2,n,m,dp);        
    }
    
    int solve(string &a,string &b,int n,int m,vector<vector<int>>&dp) // without passing strings through reference will give TLE
    {
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(a[n-1]==b[m-1])
        {
            dp[n][m]=1+solve(a,b,n-1,m-1,dp);
            return dp[n][m];
        }
        else 
        {
            dp[n][m]=max(solve(a,b,n-1,m,dp),solve(a,b,n,m-1,dp));
            return dp[n][m];
        }        
    }

// top down

int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.length();
        int m=text2.length();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
