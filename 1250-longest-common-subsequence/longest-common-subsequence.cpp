class Solution {
public:
    int f(int i1,int i2,string s1,string s2,vector<vector<int>>&dp)
    {
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2] != -1)return dp[i1][i2];

        if(s1[i1]==s2[i2])return dp[i1][i2] = 1+f(i1-1,i2-1,s1,s2,dp);
        else return dp[i1][i2] = max(f(i1-1,i2,s1,s2,dp),f(i1,i2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i = 1 ;i<=m;i++)
        {
            for(int j = 1;j<=n;j++){
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
       
    }
};