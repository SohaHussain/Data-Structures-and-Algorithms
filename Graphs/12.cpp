// shortest distance in undirected unweighted graph

// given a source node, calculate the shortest distance between the source node and all the other nodes of the graph

void bfs(vector<int> adj[],int V,int src)
{
  vector<int>dist(V,INT_MAX);
  queue<int>q;
  dist[src]=0;
  q.push(src);
  while(!q.empty())
  {
    int node = q.front();
    q.pop();
    for(auto it:adj[node])
    {
      if(dist[node]+1<dist[it]) // +1 because the graph is unweighted so we consider each edge has a unit weight
      {
        dist[it]=dist[node]+1;
        q.push(it);
      }
    }
  }
  for(auto i:dist)
    cout<<i<<" ";
}
  
