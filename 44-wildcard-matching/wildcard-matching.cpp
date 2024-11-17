class Solution {
public:
    bool f(int i,int j,string s,string p,vector<vector<int>>dp)
    {
        if(i<0 && j<0){return true;}
        if(j<0 && i>=0) {return false;}
        if(i<0 && j>=0)
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k] != '*')return false;
            }
            return true;
        }

        if(dp[i][j]!= -1)return dp[i][j];
        if(s[i]==p[j] || p[j] == '?') {return dp[i][j] = f(i-1,j-1,s,p,dp);}
        if(p[j] == '*')
        {
            return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) 
    {
        int m = s.size();
        int n = p.size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,s,p,dp);

        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));

        //base cases
        dp[0][0] = true;               // whenever i and j both <0
        for(int i = 1;i<=m;i++){        // whenever pattern exausts
            dp[i][0] = false;
        }

        for(int i=1;i<=n;i++)
        {
            bool f = true;
            for(int ii = 1;ii<=i;ii++)
            {
                if(p[ii-1] != '*')
                {
                    f = false;
                    break;
                }
            }
            dp[0][i] = f;
        }

        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1] == '?') { dp[i][j] = dp[i-1][j-1] ;}
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }

            }
        }
        return dp[m][n];

    }
};