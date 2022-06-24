void solve(int c,vector<string> &bd,vector<vector<string>> &ans,vector<int>&lr,vector<int> &ud, vector<int> &ld, int n)
    {
        if(c == n)
        {
            ans.push_back(bd);
            return;
        }
        for(int r=0;r<n;r++)
        {
            if(lr[r]==0 && ld[r+c]==0 && ud[n-1+c-r]==0)
            {
                bd[r][c]='Q';
                lr[r]=1;
                ld[r+c]=1;
                ud[n-1+c-r]=1;
                solve(c+1,bd,ans,lr,ud,ld,n);
                bd[r][c]='.';
                lr[r]=0;
                ld[r+c]=0;
                ud[n-1+c-r]=0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> bd(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            bd[i]=s;
        vector<int> leftrow(n,0);
        vector<int> upperd(2*n-1,0);
        vector<int> lowerd(2*n-1,0);
        solve(0,bd,ans,leftrow,upperd,lowerd,n);
        return ans;
    }