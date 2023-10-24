class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26),v1(26);
        int ans = 0;
        for(int i = 0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        for(int i = 0;i<t.length();i++){
            v1[t[i]-'a']++;
        }
        for(int i = 0;i<26;i++){
            ans += abs(v[i]-v1[i]);
        }
        return ans/2;
    }
};