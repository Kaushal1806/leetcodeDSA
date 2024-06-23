class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        if(n== 1 && bits[0] == 0){return true;}
        while(true)
        {
            if(i == n-1){ return true;}
            if(i>=n){return false;}

            if(bits[i] == 1){ i+=2;}
            else {i+=1;}
        }
    }
};