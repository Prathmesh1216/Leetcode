class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
        
    }
    int book(int st, int et) {
        mp[st]++;
        mp[et]--;
        int mx = 0;
        int b = 0;
        for(auto& it : mp){
            b += it.second;
            mx = max(mx,b);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */