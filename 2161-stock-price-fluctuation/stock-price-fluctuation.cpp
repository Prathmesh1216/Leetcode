class StockPrice {
public:
    map<int,int> ts;
    map<int,int> pc;
    StockPrice() {
        pc.clear();
        ts.clear();
    }
    
    void update(int timestamp, int price) {
        if(ts.find(timestamp)==ts.end()){
            pc[price]++;
            ts[timestamp] = price;
        }
        else{
            int p = ts[timestamp];
            pc[p]--;
            if(pc[p]==0) pc.erase(p);
            ts[timestamp] = price;
            pc[price]++;
        }
    }
    
    int current() {
        return ts.rbegin()->second;
    }
    
    int maximum() {
        return pc.rbegin()->first;
    }
    
    int minimum() {
        return pc.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */