class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int ele =0;
      int cnt = 0;
      for(int i =0;i<nums.size();i++)
      {
        if(cnt == 0)
        {
            ele = nums[i];
            cnt = 1;
            continue;
        }
        if(nums[i]==ele){cnt++;}
        else{cnt--;}
      }
      return ele;
    //   cnt = 0;
    //   for(int i =0;i<nums.size();i++)
    //   {
    //     if(nums[i]==ele){cnt++;}
    //   }

    }
};