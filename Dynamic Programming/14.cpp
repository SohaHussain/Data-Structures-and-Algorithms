// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

string longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.length();
        int m=text2.length();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       int i=n;
       int j=m;
       string s="";
       while(i>0 && j>0)
       {
         if(text1[i-1]==text2[j-1])
         {
           s.push_back(text1[i-1]);
           i--;
           j--;
         }
         else 
         {
           if(dp[i-1][j]>dp[i][j-1])
             i--;
           else
             j--;
         }
         reverse(s.begin(),s.end());
         return s;
     }
           
