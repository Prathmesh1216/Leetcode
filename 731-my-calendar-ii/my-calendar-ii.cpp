class MyCalendarTwo {
public:
    vector<pair<int,int>> v;
    MyCalendarTwo() {
        
    }
    bool check(vector<pair<int,int>> v,int s,int e){
        v.push_back({s,1});
        v.push_back({e,-1});
        sort(v.begin(),v.end());
        int m = 0;
        for(auto& it : v){
            m += it.second;
            if(m>=3) return false;
        }
        return true;
    }
    bool book(int start, int end) {
        if(check(v,start,end)){
            v.push_back({start,1}); 
            v.push_back({end,-1});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */