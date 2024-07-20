class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>arr(grid[0].size(),-1) ;
        for(int i=0;i<grid.size();i++)
        {
            for(int j= 0;j<grid[0].size();j++)
            {
                string s = to_string(grid[i][j]);
                int size = s.size();
                if(size > arr[j]){arr[j] = size;}
                
            }
        }
        return arr;

    }
};