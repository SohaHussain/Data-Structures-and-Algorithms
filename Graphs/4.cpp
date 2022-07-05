// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

bool checkcycle(int curr,int prev, vector<int> adj[], vector<int> &vis)
    {
        vis[curr]=1;
        for(auto it:adj[curr])
        {
            if(!vis[it])
            {
                if(checkcycle(it,curr,adj,vis))
                return true;
            }
            else if(it!=prev)
            return true;
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
                if(checkcycle(i,-1,adj,vis))
                return true;
            }
        }
        return false;
    }
