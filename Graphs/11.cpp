// 

// apply kahn's algo to find if topological sort of the given graph is possible or not
// if topo sort is posiible then graph is acyclic else graph is cyclic

bool isCyclic(int V, vector<int> adj[]) {
      vector<int>indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        indegree[it]++;
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    vector<int>ans;
	    int cnt=0;
	    while(!q.empty())
	    {
	        ans.push_back(q.front());
	        int node = q.front();
	        q.pop();
	        cnt++;
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    if(cnt==V) // if all nodes are present in topo sort order then graph is not cyclic
	    return false;
	    return true;
    }
