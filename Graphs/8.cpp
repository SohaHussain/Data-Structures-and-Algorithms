// https://leetcode.com/problems/number-of-provinces/

int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> vis(v,0);
        int ans=0;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                ans++;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(int j=0;j<isConnected[node].size();j++)
                    {
                        if(isConnected[node][j]==1 && vis[j]==0)
                        {
                            q.push(j);
                            vis[j]=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
