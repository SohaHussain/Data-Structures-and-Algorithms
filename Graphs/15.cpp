// Prim's algorithm

// brute force O(N^2)

int parent[n];
int key[n];
bool mst[n];

for(int i=0;i<n;i++)
{
  key[i]=INT_MAX;
  mst[i]=false;
  parent[i]=-1;
}

key[0]=0;

for(int count=0;count<n-1;count++) // iterating for n-1 edges
{
  int mini=INT_MAX;
  int u;
  
  // finding node with minimum edge weight which is not the part of mst
  for(int v=0;v<n;v++)
  {
    if(mst[v]==false && key[v]<mini)
    {
      mini=key[v];
      u=v;
    }
  }
  mst[u]=true;
  
  // iterating all its adjacent nodes
  for(auto it:adj[u])
  {
    int v=it.first;
    int w=it.second;
    if(mst[v]==false && w<key[v])
    {
      parent[v]=u;
      key[v]=w;
    }
  }
}

for(int i=1;i<n;i++)
  cout<<parent[i]<<"-"<<i<<'\n';


// optimized -> using priority queue  O(N+E +Nlog(N))

int parent[n];
int key[n];
bool mst[n];

for(int i=0;i<n;i++)
{
  key[i]=INT_MAX;
  mst[i]=false;
}

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pait<int,int>> pq;
key[0]=0;
parent[0]=-1;
pq.push({0,0});  // {key(weight),index}

for(int count=0;count<n-1;count++)
{
  int u=pq.top().second;
  pq.pop();
  mst[u]=true;
  for(auto it:adj[u])
  {
    int v=it.first;
    int w=it.second;
    if(mst[v]==false && w<key[v])
    {
      parent[v]=u;
      pq.push({key[v],v});
      key[v]=w;
    }
  }
}
  



  
