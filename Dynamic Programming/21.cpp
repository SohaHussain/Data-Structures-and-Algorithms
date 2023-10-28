// https://leetcode.com/problems/house-robber/

int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
            pick += dp[i-2];
            int notpick = dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
