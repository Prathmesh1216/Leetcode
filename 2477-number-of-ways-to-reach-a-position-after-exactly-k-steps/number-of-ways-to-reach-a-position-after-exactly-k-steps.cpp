class Solution {
public:
   map<pair<int,int>,long long> mp;
   int mod = 1e9+7;
    long long solve(int i,int target,int k){
        if(target-i>k) return 0;
        if(k==0){
            if(i==target) return 1;
            return 0;
        }
        if(mp.find({i,k})!=mp.end()) return mp[{i,k}];
        return mp[{i,k}] = solve(i-1,target,k-1)%mod + solve(i+1,target,k-1)%mod;
    }
    int numberOfWays(int sp, int ep, int k) {
        if(ep<sp) swap(sp,ep);
        return solve(0,ep-sp,k)%mod;
    }
};