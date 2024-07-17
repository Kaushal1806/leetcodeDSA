class Solution {
public:
    int dp[50];
    int climbStairs(int n) {

        // if(n<=2)return n;
        // return climbStairs(n-1) + climbStairs(n-2);

        memset(dp,-1,sizeof(dp));
        return mydp(n);
    }
    int mydp(int n)
    {
        if(n<=2)return n;
        
        if(dp[n] != -1)return dp[n];

        return dp[n] = mydp(n-1) + mydp(n-2);
    }
};