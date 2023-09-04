class Solution {
public:
    map<int,int> mp;
    int solve(int n){
        if(n<=1) return n;
        if(mp.find(n)!=mp.end()) return mp[n];
        return mp[n] = 1 + min(n%2+solve(n/2),n%3 + solve(n/3));
    }
    int minDays(int n) {
        return solve(n);
    }
};