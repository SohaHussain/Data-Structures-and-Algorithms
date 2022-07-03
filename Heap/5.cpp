// https://leetcode.com/problems/k-closest-points-to-origin/

 float dist(int a,int b)
    {
        float d = a*a+b*b;
        return d;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>> maxh;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++)
        {
            maxh.push({dist(points[i][0],points[i][1]),i});
            if(maxh.size()>k)
                maxh.pop();
        }
        while(maxh.size())
        {
            vector<int> t;
            t.push_back(points[maxh.top().second][0]);
            t.push_back(points[maxh.top().second][1]);
            ans.push_back(t);
            maxh.pop();
        }
        return ans;
    }
