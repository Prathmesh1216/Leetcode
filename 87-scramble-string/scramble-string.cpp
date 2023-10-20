class Solution {
public:
    map<string,int> dp;
    bool solve(string s1,string s2){
        if(s1==s2) return true;
        string key  = s1 + "_" + s2;
        if(dp.find(key)!=dp.end()) return dp[key];
        bool flag = false;
        int n = s1.length();
        for(int i = 1;i<=s1.length()-1;i++){
            if((solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i))) || (solve(s1.substr(i,n-i),s2.substr(0,n-i)) && solve(s1.substr(0,i),s2.substr(n-i,i)))) flag = true;
        }
        return dp[key] = flag;
    }   
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};