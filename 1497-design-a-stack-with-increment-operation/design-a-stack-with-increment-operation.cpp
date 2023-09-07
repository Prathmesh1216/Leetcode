class CustomStack {
public:
    vector<int> v;
    int i;
    int cs;
    int ms;
    CustomStack(int maxSize) {
        v.resize(maxSize);
        i = 0;
         cs = 0;
    }
    
    void push(int x) {
        if(cs==v.size()) return;
            v[i] = x;
            i++;
            cs++;

    }
    
    int pop() {
        if(i==0) return -1;
        i--;
        cs--;
        return v[i];
    }
    
    void increment(int k, int val) {
        for(int j = 0;j<min(cs,k);j++){
            v[j] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */