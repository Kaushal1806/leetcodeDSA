class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());

        int m = s.size();
        int n = s1.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(s[i-1] == s1[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];

                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return s.size() - dp[m][n];
    }
};