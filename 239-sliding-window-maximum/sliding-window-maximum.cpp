class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++)
        {
            //check 1 : is front index stord in the range of window , there will be max ONE ele in case
            if(!dq.empty() && dq.front() ==  (i-k))dq.pop_front();

            while(!dq.empty() && nums[dq.back()] < nums[i]){dq.pop_back();}

            dq.push_back(i);

            if( i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};