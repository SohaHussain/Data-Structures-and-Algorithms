// https://leetcode.com/problems/top-k-frequent-elements/

typedef pair<int,int> pp;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        priority_queue<pp,vector<pp>,greater<pp>> minh;
        for(auto i:mp)
        {
            minh.push({i.second,i.first});
            if(minh.size()>k)
                minh.pop();
        }
        while(minh.size())
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
