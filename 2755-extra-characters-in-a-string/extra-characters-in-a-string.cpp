class Solution {
public:
    int dp[51];
    int solve(int i,string& s,set<string>& st){
        if(i>=s.length()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 123456789;
        string temp = "";
        ans = 1 + solve(i+1,s,st);
        for(int j = i;j<s.length();j++){
            temp += s[j];
            if(st.find(temp)!=st.end()) ans = min(ans,solve(j+1,s,st));
        }
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st(dictionary.begin(),dictionary.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,st);
    }
};