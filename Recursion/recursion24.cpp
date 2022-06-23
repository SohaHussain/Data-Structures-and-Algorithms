// https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

 void solve(int ind, vector<int> &arr, vector<int> &ds, int n, vector<int> &ans)
    {
        if(ind == n)
        {
            int s = 0;
            for(auto i:ds)
            s+=i;
            ans.push_back(s);
            return;
        }
        ds.push_back(arr[ind]);
        solve(ind+1,arr,ds,n,ans);
        ds.pop_back();
        solve(ind+1,arr,ds,n,ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        sort(arr.begin(),arr.end());
        vector<int> ans;
        vector<int> ds;
        solve(0,arr,ds,N,ans);
        return ans;
    }
