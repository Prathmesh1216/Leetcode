class Solution {
public:
    int dp[51];
    int solve(int i,string& s,set<string>& st){
        if(i==s.length()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 123456789;
        for(int j = i;j<s.length();j++){
            string temp = s.substr(i,j-i+1);
            int op1 = 123456789;
            if(st.find(temp)==st.end()) op1 = j-i+1 + solve(j+1,s,st);
            else op1 = solve(j+1,s,st);
            ans = min(ans,op1);
        }
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st(dictionary.begin(),dictionary.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,st);
    }
};