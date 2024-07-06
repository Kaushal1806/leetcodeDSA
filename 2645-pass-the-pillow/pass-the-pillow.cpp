class Solution {
public:
    int passThePillow(int n, int time) {
        int r = time % (2*(n-1));
        if(r<n){return r+1;}
        else{return (2*(n-1)) - r +1;}
    }
};