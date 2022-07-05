// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

bool checkcycle(int node, vector<int> adj[],vector<int>&vis)
    {
        queue<pair<int,int>> q;
        vis[node]=1;
        q.push({node,-1});
        while(!q.empty())
        {
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto it:adj[curr])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,curr});
                }
                else if(par!=it)
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkcycle(i,adj,vis))
                return true;
            }
        }
        return false;
    }
