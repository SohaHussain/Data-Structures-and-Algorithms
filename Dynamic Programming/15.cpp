// https://leetcode.com/problems/shortest-common-supersequence/

string shortestCommonSupersequence(string str1, string str2)
    {
        int n=str1.length();
        int m=str2.length();
        
        //LCS
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(str1[i-1]==str2[j-1])
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
            if(str1[i-1]==str2[j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i][j-1]>dp[i-1][j])
            {
                s.push_back(str2[j-1]);
                j--;
            }
            else
            {
                s.push_back(str1[i-1]);
                i--;
            }
        }
        while(i>0)
        {
            s.push_back(str1[i-1]);
            i--;
        }
        while(j>0)
        {
            s.push_back(str2[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
