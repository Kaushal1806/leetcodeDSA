class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>ps(n);
        ps[0]=height[0];
        for(int i=1;i<n;i++)
        {
            ps[i] = max(ps[i-1],height[i]);
        }

        vector<int>pos(n);
        pos[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            pos[i] = max(pos[i+1],height[i]);
        }

        int total=0;
        for(int i =0;i<n-1;i++)
        {
            if(height[i]<ps[i] && height[i]<pos[i])
            {
                total += min(ps[i],pos[i]) - height[i];
            }
        }
        return total;
    }
};