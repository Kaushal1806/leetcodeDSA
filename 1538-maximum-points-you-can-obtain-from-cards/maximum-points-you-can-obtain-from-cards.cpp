class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = k-1;
        int r = cardPoints.size() - 1;
        int sum = 0;
        for(int i = 0;i<k;i++){
            sum += cardPoints[i];
        }
        int maxi = sum;
        for(int i = 0;i<k;i++)
        {
           sum += cardPoints[r];
           r--;
           sum -= cardPoints[l]; 
           l--;
           maxi = max(sum,maxi);
        }
        return maxi;
    }
};