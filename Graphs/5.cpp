// https://practice.geeksforgeeks.org/problems/bipartite-graph/1/#


	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1) // not visited
	        {
	            q.push(i);
	            color[i]=1;
	            while(!q.empty())
	            {
	                int node = q.front();
	                q.pop();
	                for(auto it:adj[node])
	                {
	                    if(color[it]==-1)
	                    {
	                        color[it]=1-color[node];
	                        q.push(it);
	                    }
	                    else if(color[it]==color[node])
	                    return false;
	                }
	            }
	        }
	    }
	    return true;
	}
