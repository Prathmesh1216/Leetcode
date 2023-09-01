class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        set<int> st(passengers.begin(),passengers.end());
        int n = passengers.size();
        int i = 0;
        int j = 0;
        int pc = 0;
        int lp = -1;
        while(i<buses.size()){
            pc = 0;
            while(j<n && passengers[j]<=buses[i] && pc<capacity){
                pc++;
                lp = passengers[j];
                j++;
            }
            i++;
        }
        cout << pc;
        int val = 0;
        if(lp==-1) val = buses[buses.size()-1];
        else if(pc==capacity) val = lp;
        else val = buses[buses.size()-1];
        int ans = 0;
        while(val>=0){
            if(st.find(val)==st.end()) return val;
            val--;
        }
        return -1;

        
    }
};