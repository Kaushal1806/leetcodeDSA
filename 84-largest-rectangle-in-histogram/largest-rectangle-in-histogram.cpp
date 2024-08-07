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


    // stack<int> st;
    //     int maxi = 0;
    //     int n = heights.size();
        
    //     for (int i = 0; i < n; ++i) {
    //         while (!st.empty() && heights[st.top()] > heights[i]) {
    //             int element = heights[st.top()];
    //             st.pop();
    //             int pse = st.empty() ? -1 : st.top();
    //             maxi = max(maxi, element * (i - pse - 1));
    //         }
    //         st.push(i);
    //     }
        
    //     while (!st.empty()) {
    //         int element = heights[st.top()];
    //         st.pop();
    //         int pse = st.empty() ? -1 : st.top();
    //         maxi = max(maxi, element * (n - pse - 1));
    //     }
        
    //     return maxi;
    // }
};