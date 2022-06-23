// https://leetcode.com/problems/permutations/

// using extra space

void solve(vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, vector<int> &f)
    {
        if(ds.size() == arr.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(f[i]==0)
            {
                ds.push_back(arr[i]);
                f[i]=1;
                solve(ds,ans,arr,f);
                ds.pop_back();
                f[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> freq(nums.size(),0);
        solve(ds,ans,nums,freq);
        return ans;
    }

// without using extra space

void solve(int ind, vector<vector<int>> &ans, vector<int> &arr)
    {
        if(ind == arr.size())
        {
            ans.push_back(arr);
            return;
        }
        for(int i = ind; i<arr.size();i++)
        {
            swap(arr[i],arr[ind]);
            solve(ind+1,ans,arr);
            swap(arr[i],arr[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;        
        solve(0,ans,nums);
        return ans;
    }
