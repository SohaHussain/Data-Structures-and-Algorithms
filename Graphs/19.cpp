// https://leetcode.com/problems/find-eventual-safe-states/description/

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<vector<int>> g(n);
        vector<int> outdegree(n);
        vector<int> safe(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            for(auto it: graph[i])
            g[it].push_back(i);
            outdegree[i]=graph[i].size();
            if(outdegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            safe[node]=1;
            for(auto it:g[node])
            {
                outdegree[it]--;
                if(outdegree[it]==0)
                q.push(it);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(safe[i])
            ans.push_back(i);
        }
        return ans;
    }
