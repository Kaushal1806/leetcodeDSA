class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>vec;
        int lb = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ub = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lb == ub ) 
        {
            vector<int>v ={-1,-1};
            return v;

        }
        else
        {
            vec.push_back(lb);
            vec.push_back(ub-1);

        }
        return vec;
    }
};