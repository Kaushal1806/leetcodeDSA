class Solution {
public:
int dp[1005];

// dp=(n*m*...*z <=1e7)
// recuration => 2^n => recursive*dp<1e9 => 2*n
    int solver(int ind,vector<int>& arr){
        if(ind>=arr.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind]=min(solver(ind+1,arr)+arr[ind],solver(ind+2,arr)+arr[ind]);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(solver(0,cost),solver(1,cost));
    }
};