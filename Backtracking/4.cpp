// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

void solve(int r,int c,vector<vector<int>>&m, int n, vector<string>&ans,string path,vector<vector<int>>&vis)
    {
        // base case when rat reaches destination .ie. m[n-1][n-1]
        if(r==n-1 && c==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        // moving downward
        if(r+1<n && vis[r+1][c]==0 && m[r+1][c]==1)
        {
            vis[r][c]=1;
            solve(r+1,c,m,n,ans,path+'D',vis);
            vis[r][c]=0;
        }
        
        // moving left
        if(c-1>=0 && vis[r][c-1]==0 && m[r][c-1]==1)
        {
            vis[r][c]=1;
            solve(r,c-1,m,n,ans,path+'L',vis);
            vis[r][c]=0;
        }
        
        // moving right
        if(c+1<n && vis[r][c+1]==0 && m[r][c+1]==1)
        {
            vis[r][c]=1;
            solve(r,c+1,m,n,ans,path+'R',vis);
            vis[r][c]=0;
        }
        
        // moving up
        if(r-1>=0 && vis[r-1][c]==0 && m[r-1][c]==1)
        {
            vis[r][c]=1;
            solve(r-1,c,m,n,ans,path+'U',vis);
            vis[r][c]=0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
      
      //declaring and initializing visited 2D array with 0
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==1)
        solve(0,0,m,n,ans,"",vis);
        return ans;
    }
