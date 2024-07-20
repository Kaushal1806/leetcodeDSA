class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        for(int i =1;i<=grid.size()*grid.size();i++)
        {
            mp[i]=0;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
              mp[grid[i][j]]++;  
            }
        } 
        int r;
    int mis;
    for(auto it:mp)
    {
        if(it.second == 0)
        {
            mis = it.first;
        }
        if(it.second == 2)
        {
            r = it.first;
        }
    }
    vector<int>ans;
    ans.push_back(r);
    ans.push_back(mis);
    return ans;
    }
    
};