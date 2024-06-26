class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int n = nums.size();
        if(n == 0)return 0;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }

        int longest = 1;
        for(auto i :s)
        {
            //now we want starting of sequence , i.e no smaller element should be present
            if(s.find(i-1) == s.end()) 
            {
                int cnt = 1;
                i++;
                while(s.find(i)!= s.end())
                {
                    cnt++;
                    i++;
                }
                longest = max(longest,cnt);
            }
            
        }
        return longest;
    }
};