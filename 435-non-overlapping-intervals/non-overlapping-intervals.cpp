class Solution {
public:
    static bool cmp(vector<int> v1,vector<int>v2)
    {
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt = 0;
        int time = INT_MIN;
        for(int i = 0;i<intervals.size();i++)
        {   
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(intervals[i][0]>=time)
            {
                cnt++;
                time  = max(time,intervals[i][1]);
            }
        }
        return intervals.size() - cnt;
    }
};