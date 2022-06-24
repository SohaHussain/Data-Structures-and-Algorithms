
// https://leetcode.com/problems/sudoku-solver/

// https://takeuforward.org/data-structure/sudoku-solver/

bool isvalid(vector<vector<char>> &b,int r,int c,char n)
    {
        for(int i=0;i<9;i++)
        {
            if(b[i][c]==n)
                return false;
            if(b[r][i]==n)
                return false;
            if (b[3*(r/3)+i/3][3*(c/3)+i%3]==n)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char n='1';n<='9';n++)
                    {
                        if(isvalid(board,i,j,n))
                        {
                            board[i][j]=n;
                            if(solve(board))
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
    }
