class Solution {
public:
    int f(int ind,int allow,vector<int>prices,vector<vector<int>>&dp)
    {
        if(ind == prices.size())
        {
            return 0;
        }
        if(dp[ind][allow] != -1)return dp[ind][allow];
        long profit =0;
        if(allow)
        {
            profit = max( -prices[ind] + f(ind+1,0,prices,dp) , f(ind+1,1,prices,dp));
        }
        else
        {
            profit = max( prices[ind] + f(ind+1,1,prices,dp) , f(ind+1,0,prices,dp) );
        }
        return dp[ind][allow] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(m,vector<int>(2,-1));
        // return f(0,1,prices,dp);

        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        dp[n][0] = dp[n][1] = 0;
        for(int ind =n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                long profit =0;
                if(buy){
                    profit = max( -prices[ind] + dp[ind+1][0] , dp[ind+1][1]);
                }
                else
                {
                    profit = max( prices[ind] + dp[ind+1][1] , dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];

    }

};