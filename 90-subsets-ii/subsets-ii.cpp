class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        pnp(0,ds,nums,nums.size(),ans);
        vector<vector<int>>v;
        for(auto it : ans){v.push_back(it);}
        return v;
    }
    void pnp(int curr_index,vector<int>&ds,vector<int>&arr,int n,set<vector<int>>&ans)
    {
        if(curr_index == n)
        {
            ans.insert(ds);
            return;
        }

        ds.push_back(arr[curr_index]);
        pnp(curr_index + 1, ds,arr,n,ans);
        ds.pop_back();

        pnp(curr_index + 1, ds,arr,n,ans);

    }
};