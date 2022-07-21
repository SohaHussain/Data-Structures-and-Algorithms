// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

int minDeletions(string str, int n) 
{ 
    string str2="";
    int i=n-1;
    while(i>=0)
    {
        str2+=str[i];
        i--;
    }
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(str[i-1]==str2[j-1])
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
    return (n-lcs);
} 
