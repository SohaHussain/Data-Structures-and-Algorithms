// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

int countsubset(int s,int arr[])
{
  int n=arr.size();
  int dp[n+1][s+1];
  
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=s;j++)
    {
      if(j==0)
        dp[i][j]=1;
      else if(i==0)
        dp[i][j]=0;
      else if(arr[i]<=j)
        dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  return dp[n][s];
}
      
