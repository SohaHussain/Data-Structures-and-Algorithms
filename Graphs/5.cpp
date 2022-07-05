// https://practice.geeksforgeeks.org/problems/bipartite-graph/1/#


	bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1); // initializing vector of size n with all values as -1
        queue<int> q; // queue to keep track of which node to traverse next
        for(int i=0;i<n;i++)
        {
            // check if visited or not
            if(color[i]==-1) // not visited
            {
                color[i]=1; // marking as visited and assigning color 1
                q.push(i); // pushing in queue to traverse next
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(auto it:graph[node]) // traversing adjacent nodes
                    {
                        // checking whether adjacent nodes are traversed or not
                        if(color[it]==-1) // adjacent node not traversed
                        {
                            color[it]=1-color[node]; // marking and assigning opposite color to adjacent node
                            q.push(it);
                        }
                        else if(color[it]==color[node]) // if both adjacent nodes have same color
                            return false; // not bipartite
                    }
                }
            }
        }
        return true; // graph is bipartite
    }
