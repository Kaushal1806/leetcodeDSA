class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()] ;
        for(int i = 0;i<nums.size();i++){freq[i] = 0 ;}
        recurP(freq,nums,ds,ans);
        return ans;
    }

    void recurP(int freq[],vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = 0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurP(freq,nums,ds,ans);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
};