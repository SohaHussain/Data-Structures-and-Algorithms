// https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628

#define MOD 1000000007
int countPartitions(int n, int d, vector<int> &arr) {
    int s=0;
    for(auto i:arr)
    s+=i;
    if(s-d<0 || (s-d)%2==1)
    return 0;
    s=(s-d)/2;
    vector<vector<int>> dp(n,vector<int>(s+1,0));
    
    if(arr[0]==0)
    dp[0][0]=2; // if sum also =0 then two cases take or not take
    
    else
    dp[0][0]=1; // if sum=0 but first elemnt not=0 then one case, don't take
    
    if(arr[0]!=0 && arr[0]<=s)
    dp[0][arr[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            int nottake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j)
            take=dp[i-1][j-arr[i]];
            dp[i][j]=take+nottake;
            dp[i][j]%=MOD;
        }
    }
    return dp[n-1][s];

}
