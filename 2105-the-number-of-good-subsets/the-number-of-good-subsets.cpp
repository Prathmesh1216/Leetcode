class Solution {
public:
    // primes = {2,3,5,7,9,11,13,17,19,23,29} {0,1,2,3,4,5,6,7,8,9}
    int m = 1e9+7;
    int power(long long a,long long b){
        if(b==0) return 1;
        if(b&1) return (a*power(a,b-1))%m;
        return power((a*a)%m,b/2)%m;
    }
    vector<int> primes = {2,3,5,7,9,11,13,17,19,23,29};
    int pf(int a){
        int mask = 0;
        for(int i = 0;i<primes.size();i++){
            int cnt = 0;
            while(a>1 && a%primes[i]==0){
                cnt++;
                a/=primes[i];
            }
            if(cnt>1) return -1;
            if(cnt==1) mask|=(1<<i);
        }
        return mask;
    }
    int solve(int i,int mask,vector<int>& vmask,vector<int>& v,vector<vector<int>>& dp,vector<int>& vis){
        if(i==v.size()) return mask!=0;
        if(dp[i][mask]!=-1) return dp[i][mask];
        bool flag = true;
        if(mask&(vmask[v[i]])) flag = false;
        long long ans = 0;
        if(flag) ans = (ans + vis[v[i]]*1LL*solve(i+1,mask|vmask[v[i]],vmask,v,dp,vis))%m;
        ans = (ans + solve(i+1,mask,vmask,v,dp,vis))%m;
        return dp[i][mask] = ans%m;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> vis(31);
        vector<int> vmask(31);
        vector<int> v;
      //  memset(dp,-1,sizeof(dp));
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1){
               vis[nums[i]]++;
                continue;
            }
            if(!vis[nums[i]]){
                vis[nums[i]] = 1;
                if(pf(nums[i])!=-1) vmask[nums[i]] = pf(nums[i]),v.push_back(nums[i]);
            }
            else vis[nums[i]]++;
        }
        vector<vector<int>> dp(v.size()+1,vector<int>(2048,-1));
        long long  ans = solve(0,0,vmask,v,dp,vis);
        if(vis[1]>0) ans = (ans*((int)power(2,vis[1]))%m)%m;
        return ans;
    }
};