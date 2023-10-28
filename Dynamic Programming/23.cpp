// https://leetcode.com/problems/unique-paths/description/

int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) // starting position
                {
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0) // possible to move upwards from current position
                up=dp[i-1][j];
                if(j>0) // possible to move left from current position
                left=dp[i][j-1];
                dp[i][j]=up+left; // storing all possible ways to reach the current position
            }
        }
        return dp[m-1][n-1]; // no. of ways to reach the last cell
    }
