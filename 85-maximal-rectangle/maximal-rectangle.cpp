class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxi = 0;
        int n = heights.size();
        for(int i=0;i<n;++i)
        {
            while(!st.empty()&& heights[st.top()] > heights[i])
            {
                int element = heights[st.top()];
                st.pop();
                // int nse = i;
                int pse = st.empty()?-1:st.top();
                maxi = max(maxi, (element*(i-pse-1))  );
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int element = heights[st.top()];
            st.pop();
            // int nse = n;
            int pse = st.empty()?-1:st.top();
            maxi = max(maxi, (element*(n-pse-1))  );
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
         if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Initialize heights array
        vector<int> heights(n, 0);
        int maxA = 0;
        
        // Convert char matrix to integer heights matrix
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (matrix[i][j] == '1') 
                {
                    heights[j] += 1;
                } 
                else 
                {
                    heights[j] = 0;
                }
            }
            // Find the maximum rectangle area in the histogram
            maxA = max(maxA, largestRectangleArea(heights));
        }
         return maxA;
    }
};