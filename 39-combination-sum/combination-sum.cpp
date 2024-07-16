class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        pnp(0,target,ds,candidates,ans);
        return ans;
                
    }

    void pnp(int ind,int target,vector<int>&ds,vector<int>&arr,vector<vector<int>>&ans)
    {
        if(ind == arr.size())
        {
            if(target == 0)
            {
             ans.push_back(ds);
            }
            return;
        }

        if(arr[ind]<= target)
        {
            ds.push_back(arr[ind]);
            pnp(ind,target - arr[ind],ds,arr,ans);
            ds.pop_back();
        }

         pnp(ind+1,target,ds,arr,ans);

    }
};