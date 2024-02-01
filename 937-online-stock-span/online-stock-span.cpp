class StockSpanner {
public:
    stack<pair<int,int>>st;
    int idx;
    StockSpanner() {
        st.push({0,1e5+1});
        idx=0;
    }
    
    int next(int price) {
        while(st.size()>1 && price>=st.top().second) st.pop();
        idx++;
        int ans=idx-st.top().first;
        st.push({idx,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */