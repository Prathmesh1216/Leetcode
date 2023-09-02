class Solution {
public:
    int n;
    vector<int> dp;
    bool solve(int i,int k,int sum,int target,int mask,vector<int>& matchSticks){
       if(k==0) return 1; 
        if(sum==target) return solve(0,k-1,0,target,mask,matchSticks);
        if(dp[mask]!=-1) return dp[mask];
        bool ans = false;
        for(int j = i;j<n;j++){
            if(!(mask&(1<<j)) && sum+matchSticks[j]<=target) ans|=solve(j+1,k,sum+matchSticks[j],target,mask|(1<<j),matchSticks);
        }
        return dp[mask] = ans;

    }
    bool makesquare(vector<int>& matchSticks) {
        n = matchSticks.size();
        int sum = 0;
        vector<int> v(3);
        dp.resize((1<<n)-1,-1);
        for(auto it : matchSticks) sum+=it;
        if(sum%4) return false;
        int side = sum/4;
        return solve(0,3,0,side,0,matchSticks);
    }
};