class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int length =0;
        while(r<s.size())
        {
            if(mp.find(s[r])!= mp.end())
            {
                if(mp[s[r]]>=l){ l = mp[s[r]] + 1; } // >= works only > dont work , try for abcdea , here a's prev occ is at 0 and l is at also 0 , so meet condition put = with >
            }
            
            mp[s[r]] = r;
            length = max(length,r-l+1);
            r++;
        }
        return length ;
    }
};