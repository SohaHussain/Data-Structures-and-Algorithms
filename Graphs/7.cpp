// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/#

bool checkCycle(int node, vector < int > adj[], vector<int>&vis,vector<int>&dfsVis) 
    {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) 
      {
        if (!vis[it]) 
        {
          if (checkCycle(it, adj, vis, dfsVis)) 
          return true;
        } 
        else if (dfsVis[it]) 
        {
          return true;
        }
      }
      dfsVis[node] = 0;
      return false;
    }
    
    bool isCyclic(int N, vector < int > adj[])
    {
      vector<int>vis(N,0);
      vector<int>dfsVis(N,0);

      for (int i = 0; i < N; i++) 
      {
        if (!vis[i]) 
        {
          if (checkCycle(i, adj, vis, dfsVis))
          {
            return true;
          }
        }
      }
      return false;
    }
