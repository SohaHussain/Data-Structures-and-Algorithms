// https://leetcode.com/problems/number-of-enclaves/

int n, m;

    void dfs(int r,int c, vector<vector<int>> &vis, int row[], int col[], vector<vector<int>> &mat)
    {
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr<n && nc<m && nr>=0 && nc>=0 && !vis[nr][nc] && mat[nr][nc]==1)
            dfs(nr,nc,vis,row,col,mat);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};

        // boundary rows
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
            dfs(0,j,vis,row,col,grid);
            if(!vis[n-1][j] && grid[n-1][j]==1)
            dfs(n-1,j,vis,row,col,grid);
        }

        // boundary columns
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            dfs(i,0,vis,row,col,grid);
            if(!vis[i][m-1] && grid[i][m-1]==1)
            dfs(i,m-1,vis,row,col,grid);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                ans++;
            }
        }
        return ans;
    }
