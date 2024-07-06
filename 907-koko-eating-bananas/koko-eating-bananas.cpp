class Solution {
public:
    int maxi(vector<int>arr)
    {
        int x = INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            x = max(x,arr[i]);
        }
        return x;
    }

    long long hoursreq(vector<int>&arr,int k)
    {
        long long time =0;
        for(int i=0;i<arr.size();i++)
        {
            time += ceil((double)arr[i]/(double)k);
        }
        return time;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1;
        long long hi = maxi(piles);
        while(l<=hi)
        {
            long long mid = (l+hi)/2;
            long long totalhours = hoursreq(piles,mid);
            if(totalhours<=h){hi = mid -1;}
            else{l = mid +1;}

        }
        return l;
    }
};