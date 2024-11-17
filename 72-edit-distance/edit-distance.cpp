class Solution {
public:
    int f(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
        if(i<0)return j+1;
        if(j<0)return i+1;

        if(dp[i][j]!= -1)return dp[i][j];

       if(s[i] == t[j])
       {
        return dp[i][j] =  f(i-1,j-1,s,t,dp);
       } 

       else
       {
        return dp[i][j] =  1+ min(f(i-1,j,s,t,dp), min(f(i,j-1,s,t,dp),f(i-1,j-1,s,t,dp)) );
       }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,word1,word2,dp);

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        for(int i = 0;i<=m;i++)dp[i][0] = i; 
        for(int j = 0;j<=n;j++)dp[0][j] = j; 

        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }

        return dp[m][n];
    }
};