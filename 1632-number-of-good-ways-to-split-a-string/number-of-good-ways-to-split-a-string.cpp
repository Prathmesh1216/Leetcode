class Solution {
public:
    int numSplits(string s) {
        vector<bool> v(26);
        int n = s.length();
        vector<int> ldis(n);
        vector<int> rdis(n);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(!v[s[i]-'a']){
                cnt ++;
                v[s[i]-'a'] = 1;
            }
            ldis[i] = cnt;
        }
        vector<bool> v1(26);
        cnt = 0;
        for(int i = n-1;i>=0;i--){
            rdis[i] = cnt;
            if(!v1[s[i]-'a']){
                v1[s[i]-'a'] = 1;
                cnt++;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
           // cout << ldis[i] << " " << rdis[i] << endl;
            if(ldis[i]==rdis[i]) ans++;
        }
        return ans;
    }
};