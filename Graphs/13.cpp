// shortest path in weighted DAG

void toposort(int node,vector<int>&vis,stack<int>&st,vector<pair<int,int>>adj[])
{
  vis[node]=1;
  for(auto it:adj[node])
  {
    if(!vis[it.first])
      toposort(it.first,vis,st,adj);
  }
  st.push(node);
}

void shortestpath(int src,int v,vector<pair<int,int>>adj[])
{
  vector<int>vis(v,0);
  stack<int>st;
  for(int i=0;i<v;i++)
  {
    if(!vis[i])
      toposort(i,vis,st,adj);
  }
  vector<int>dis(v,INT_MAX);
  dist[src]=0;
  while(!st.empty())
  {
    int node = st.top();
    st.pop();
    if(dist[node]!=INT_MAX)
    {
      for(auto it:adj[node])
      {
        if(dist[node]+it.second<dist[it.first])
          dist[it.first]=dist[node]+it.second;
      }
    }
  }
  for(int i=0;i<v;i++)
  {
    if(dist[i]==INT_MAX)
      cout<<"infinity(not approachable)\n";
    else
      cout<<dist[i]<<'\n;
    }
}
