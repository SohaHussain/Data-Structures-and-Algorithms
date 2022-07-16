// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// top down approach

int knapSack(int W, int wt[], int val[], int n) 
    { 
       int i, w; 
       int dp[n+1][W+1]; 
      
       //building table K[][] in bottom up manner.
       for (i = 0; i <= n; i++) 
       { 
           for (j = 0; j <= W; j++) 
           { 
                //base case  
                if (i==0 || j==0) 
                    dp[i][j] = 0; // initialization of table
                
                //if weight of current item is more than Knapsack capacity W
                //then this item cannot be included in the optimal solution. 
                else if (wt[i-1] <= j) 
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]); 
                    
                //else updating dp[i][j] as dp[i-1][j].   
                else
                    dp[i][j] = dp[i-1][j]; 
           } 
       } 
       //returning the result.
       return dp[n][W]; 
    }
