class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int p) {
        int cnt = 1;
        if(st.empty()) {st.push({p,cnt});return cnt;}
        while(!st.empty() && st.top().first<=p) cnt += st.top().second,st.pop();
        st.push({p,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */