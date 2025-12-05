class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<int,int>mp;
        // vector<int> ans(2);
        // for(int i=0;i<nums.size();i++)
        // {
        //     mp[nums[i]] = i;
        // }
        // for(int i=0;i<nums.size();i++){
        //     if((mp[target -nums[i]] != i) && (mp.find(target -nums[i]) != mp.end()) ){
        //         ans[0] = i;
        //         ans[1] = mp[target - nums[i]];
        //         return ans;
        //     }
            
        // }
        // return ans;

        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            auto it = mp.find(complement);
            if (it != mp.end()) {
                return {it->second, i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};