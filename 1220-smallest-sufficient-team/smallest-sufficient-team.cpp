class Solution {
public:
    int n;
    int m;
    unordered_map<string,int> mp;
    vector<int> res;
    vector<vector<int>> dp;
    void solve(int i,int mask,vector<int>& sp,vector<int>& ans){
        if(i==n){
            if(mask==(1<<m)-1)if(res.size()==0 || ans.size()<res.size()) res = ans;
            return;
        }
        if(dp[i][mask]!=-1){
            if(dp[i][mask]<=ans.size()) return;
        }
        solve(i+1,mask,sp,ans);
        ans.push_back(i);
        solve(i+1,mask|sp[i],sp,ans);
        ans.pop_back();
        if(ans.size()>0) dp[i][mask] = ans.size();
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = people.size();
        m = req_skills.size();
        for(int i = 0;i<m;i++){
            mp[req_skills[i]] = (1<<i);
        }
        vector<int> sp; // to store people skill bits
        for(auto it : people){
            int mask = 0;
            for(auto iit : it){
                if(mp.count(iit)) mask = mask|mp[iit];
            }
            sp.push_back(mask);
        }
        dp.resize(n,vector<int>((1<<m),-1));
        vector<int> ans;
        solve(0,0,sp,ans);
        return res;
    }
};