// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// recursive (TLE)

int solve(int arr[],int i,int j)
    {
        if(i>=j)
        return 0;
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            ans=min(ans,temp);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return solve(arr,1,N-1);
    }

// memoization (bottom up)

int static dp[101][101];
class Solution{
public:
    
    int solve(int arr[],int i,int j)
    {
        if(i>=j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            ans=min(ans,temp);
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {       
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
};
