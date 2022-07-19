// https://leetcode.com/problems/target-sum/

int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++)
            s+=nums[i];
        int ns= (target+s);
        if(s<abs(target) || (ns%2)!=0)
            return 0;
        ns=ns/2;
        int dp[n+1][ns+1];
        
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int j=1;j<=ns;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
          // starting from zero because 0 is valid constraint
            for(int j=0;j<=ns;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else 
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][ns];
    }
