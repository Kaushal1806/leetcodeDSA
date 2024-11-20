class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0;
        int r =0;
        int zcnt =0;

        int maxl = 0;
        while(r<nums.size())
        {
            if(nums[r]==0)zcnt++;
            if(zcnt<=k)
            {
                maxl = max(maxl,r-l+1);
            }
            // else
            // {
            //     while(zcnt>k)
            //     {
            //         if(nums[l]==0)zcnt--;
            //         l++;
            //     }
            // }
            else
            {
                if(nums[l]==0)zcnt--;
                l++;
            }
            r++;
        } 
        return maxl;
    }
};