class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) 
    {
        vector<int>v(matrix[0].size(),-1);

        for(int i=0;i<matrix.size();i++)
        {
           for(int j=0;j<matrix[0].size();j++)
           {
                if(matrix[i][j] > v[j]) {v[j] = matrix[i][j];}
           } 
        }
        for(int i=0;i<matrix.size();i++)
        {
           for(int j=0;j<matrix[0].size();j++)
           {
                if(matrix[i][j] ==-1) { matrix[i][j] = v[j];}
           } 
        }
        return matrix;
    }
};