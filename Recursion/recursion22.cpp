// https://leetcode.com/problems/combination-sum/

// applying take/not take method

void solve(int ind,int n, vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr,int t)
    {
        if(ind==n)
        {
            if(t==0)
                ans.push_back(ds);
                return;
        }
        if(arr[ind]<=t)
        {
            ds.push_back(arr[ind]);
            solve(ind,n,ans,ds,arr,t - arr[ind]);
            ds.pop_back();
        }
        solve(ind+1,n,ans,ds,arr,t);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        solve(0,n,ans,ds,candidates,target);
        return ans;
    }
