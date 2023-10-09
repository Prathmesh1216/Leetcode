class Solution {
public:
    int oc(vector<vector<int>>& g,int r,int l){
        int cnt = 0;
        for(int i = 0;i<26;i++){
            if((g[r+1][i] - g[l][i])&1) cnt++;
        }
        return cnt;
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>> g;
        vector<int> v(26);
        g.push_back(v);
        for(int i = 0;i<n;i++){
            v[s[i]-'a']++;
            g.push_back(v);
        }
        vector<bool> ans;
        for(auto& it : queries){
            int odd = oc(g,it[1],it[0]);
            if(odd/2<=it[2]) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};