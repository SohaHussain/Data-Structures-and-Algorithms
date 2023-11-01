// https://leetcode.com/problems/01-matrix/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        int row[]={-1,0,+1,0};
        int col[]={0,+1,0,-1};

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[r][c]=steps;
            for(int i=0;i<4;i++)
            {
                int nr=r+row[i];
                int nc=c+col[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},steps+1});
                }
            }
        }
        return dis;
    }
