class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;

        int maxl = 0;
        map<int ,int>mp;

        while(r<fruits.size())
        {
            mp[fruits[r]]++;
            if(mp.size()<=2)
            {
                maxl = max(maxl,r-l+1);

            }
            else
            {
                while(mp.size()>2)
                {
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0){
                        mp.erase(fruits[l]);
                    }
                    l++;
                }
            }
            r++;
        }
        return maxl;
        
    }
};