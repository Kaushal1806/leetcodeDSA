class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 1;
        int h = nums.size()-1;
        if(nums.size()==1){return 0;}
        // if(nums.size()==2)
        // {
        //     if(nums[0]>nums[1]){return 0;}
        //     else{return 1;}
        // }
        if(nums[0]>nums[1]){return 0;}
        if(nums[h]>nums[h-1]){return h;}
        h--;
        while(l<=h)
        {
            int mid =(l+h)/2;

            if(nums[mid-1]<nums[mid] && nums[mid]> nums[mid+1]) return mid;

            else if(nums[mid-1]<nums[mid] && nums[mid]< nums[mid+1]) { l = mid +1;}

            else{h = mid -1;}
        }
        return -1;
    }
};