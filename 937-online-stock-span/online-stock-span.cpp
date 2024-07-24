class StockSpanner {
public:
    vector<int>v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int i = v.size()-1;
        int cnt = 0;
        while(i>=0 && v[i]<=price)
        {
            cnt++;
            i--;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */