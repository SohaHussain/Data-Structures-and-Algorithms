// https://practice.geeksforgeeks.org/problems/topological-sort/1/#

vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	    while(!q.empty())
	    {
	        ans.push_back(q.front());
	        int node = q.front();
	        q.pop();
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    return ans;
	}
