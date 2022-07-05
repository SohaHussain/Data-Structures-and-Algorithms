// depth first search (DFS) 

void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int>ans)
{
    ans.push_back(node);
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        dfs(it,vis,adj,ans);
    }
}

vector<int> solve(int v, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        dfs(i,vis,adj,ans);
    }
    return ans;
}
