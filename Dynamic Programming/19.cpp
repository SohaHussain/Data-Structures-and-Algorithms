// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

int LongestRepeatingSubsequence(string str)
		{
		    int n=str.length();
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++)
		    {
		        for(int j=0;j<=n;j++)
		        {
		            if(i==0 || j==0)
		            dp[i][j]=0;
		            else if(i!=j && str[i-1]==str[j-1]) // i should not be equal to j
		            dp[i][j]=dp[i-1][j-1]+1;
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
