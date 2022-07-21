// https://leetcode.com/problems/longest-palindromic-subsequence/

int longestPalindromeSubseq(string a) 
    {
        int n=a.length();
        string b="";
        int i=n-1;
        while(i>=0)
        {
            b+=a[i];
            i--;
        }
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int lcs=INT_MIN;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                lcs=max(lcs,dp[i][j]);
        }
        return lcs;
    }
