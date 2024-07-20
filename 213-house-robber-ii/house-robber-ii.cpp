class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        vector<int>dp2(n,-1);
        vector<int>temp1,temp2;
        for(int i= 0;i<n;i++)
        {
            if(i != 0){temp1.push_back(nums[i]);}
            if(i != n-1){temp2.push_back(nums[i]);}
        }
        int a = mydp(n-2,temp1,dp);
        int b = mydp(n-2,temp2,dp2);
        return max(a,b);

    }

    int mydp(int n,vector<int>&nums,vector<int>&dp)
    {
        if(n==0)return nums[0];
        if(n<0)return 0;

        if(dp[n]!= -1)return dp[n];
        int pick = nums[n] + mydp(n-2,nums,dp);
        int notpick = 0 + mydp(n-1,nums,dp);

        return dp[n] = max(pick,notpick);
    }
    
};