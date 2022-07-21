// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

int minOperations(string str1, string str2) 
	{ 
	    int n=str1.length();
	    int m=str2.length();
	    int dp[n+1][m+1];
  //LCS
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(i==0 || j==0)
	            dp[i][j]=0;
	            else if(str1[i-1]==str2[j-1])
	            dp[i][j]=1+dp[i-1][j-1];
	            else 
	            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    int lcs=INT_MIN;
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        lcs=max(lcs,dp[i][j]);
	    }
	    int d=n-lcs; // deletions from string a
	    int i=m-lcs; // insertions in string b
	    return (d+i);
	} 
