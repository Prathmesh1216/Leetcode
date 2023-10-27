class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return (a[0]==b[0])?a[1]>b[1]:a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n = envelopes.size();
        vector<int> dp;
        dp.push_back(envelopes[0][1]);
        for(int i = 1;i<n;i++){
            if(envelopes[i][1]>dp.back()) dp.push_back(envelopes[i][1]);
            else{
                auto it  = lower_bound(dp.begin(),dp.end(),envelopes[i][1]) - dp.begin();
                dp[it] = envelopes[i][1];
            }
        }
        return dp.size();

    }
};