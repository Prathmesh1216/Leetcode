class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        map<char,int> mp;
        vector<int> dl(n);
        vector<int> dr(n);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
            dl[i] = mp.size();
        }
        mp.clear();
        mp[s[n-1]]++;
        for(int i = n-2;i>=0;i--){
            dr[i] = mp.size();
            mp[s[i]]++;
        }
        for(int i = 0;i<n-1;i++){
            if(dl[i]==dr[i]) cnt++;
        }
        return cnt;
    }
};