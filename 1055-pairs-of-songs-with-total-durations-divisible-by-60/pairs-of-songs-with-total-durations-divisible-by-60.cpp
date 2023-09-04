class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> mp;
        int n = time.size();
        mp[time[n-1]%60] = 1;
        int ans = 0;
        for(int i = n-2;i>=0;i--){
            if(60-time[i]%60==60) ans += mp[0];
            if(mp[60-time[i]%60]>0) ans += mp[60-time[i]%60];
            mp[time[i]%60]++;
        }
        return ans;

    }
};