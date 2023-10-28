// https://leetcode.com/problems/unique-paths-ii/

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
        return 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1; // path to reach starting point
                    continue;
                }

                if(i>0 && j>0 && grid[i][j]==1)
                {
                    dp[i][j]=0; // no path to reach obstacle
                    continue;
                }

                int up=0;
                int left=0;

                if(i>0 && grid[i][j]==0)
                up=dp[i-1][j];
                if(j>0 && grid[i][j]==0)
                left=dp[i][j-1];

                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
