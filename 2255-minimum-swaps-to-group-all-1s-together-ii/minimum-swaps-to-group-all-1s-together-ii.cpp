class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k= 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(nums[i]==1)k++;
        }
        for(int i = 0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }

        int zero = 0;
        int ans =0;
        for(int i=0;i<k;i++)
        {
            if(nums[i] == 0)zero++;
        }
        ans = zero;
        for(int i = 1;i<nums.size()-k ;i++)
        {
            if(nums[i-1] == 0)zero--;
            if(nums[i+k-1]==0)zero++;
            ans = min(ans,zero);
        }
        return ans;


    }
};