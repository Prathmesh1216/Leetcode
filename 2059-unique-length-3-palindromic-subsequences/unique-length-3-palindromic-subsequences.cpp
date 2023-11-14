class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> fo(26),lo(26),count(26);
        for(int i = 0;i<n;i++) lo[s[i]-'a'] = i;
        for(int i = n-1;i>=0;i--) fo[s[i]-'a'] = i;
        for(int i = 0;i<n;i++) count[s[i]-'a']++;
        int cnt = 0;
        for(int i = 0;i<26;i++){
            if(count[i]>=2){
                vector<bool> vis(26);
                for(int j = fo[i]+1;j<lo[i];j++){
                    vis[s[j]-'a'] = 1;
                }
                for(auto it : vis) cnt += it;
            }
        }
        return cnt;
    }
};