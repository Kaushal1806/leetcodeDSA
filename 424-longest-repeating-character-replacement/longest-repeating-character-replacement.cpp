class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxl = 0;
        int maxf = 0;
        int hash[26] = {0};

        while(r<s.size())
        {
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);
            if(r-l+1-maxf <= k )
            {
                maxl = max(maxl,r-l+1);
            }
            else
            {
                hash[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return maxl;
    }
};