// https://leetcode.com/problems/combination-sum-ii/

// https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/

void solve(int ind,vector<vector<int>> &ans,vector<int> &ds,vector<int> &arr,int t)
    {
        if(t==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && (arr[i]==arr[i-1]))
                continue;
            if(arr[i]>t)
                break;
            ds.push_back(arr[i]);
            solve(i+1,ans,ds,arr,t-arr[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        solve(0,ans,ds,candidates,target);
        return ans;
    }
