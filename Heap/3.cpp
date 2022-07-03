// https://leetcode.com/problems/find-k-closest-elements/

// in max/min heap of type pair, sorting is done based on key i.e. pair.first

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            maxh.push({abs(x-arr[i]),arr[i]});
            if(maxh.size()>k)
                maxh.pop();
        }
            while(maxh.size())
            {
                ans.push_back(maxh.top().second);
                maxh.pop();
            }
        sort(ans.begin(),ans.end());    
        return ans;
    }
