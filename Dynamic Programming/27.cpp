// https://leetcode.com/problems/minimum-falling-path-sum/description/

int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n));
        //variable starting point
        for(int i=0;i<n;i++)
        dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=INT_MAX;
                int diagl=INT_MAX;
                int diagr=INT_MAX;
                up=dp[i-1][j]+matrix[i][j];
                if(j>0)
                diagl=dp[i-1][j-1]+matrix[i][j];
                if(j+1<n)
                diagr=dp[i-1][j+1]+matrix[i][j];
                dp[i][j]=min(up,min(diagl,diagr));
            }
        }

        // returning the min sum path from variable end points
        for(int j=0;j<n;j++)
        ans=min(ans,dp[n-1][j]);
        return ans;
    }
