class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = pattern.length();
        for(int i = 0;i<words.size();i++){
            unordered_map<char,char> mp,mp1;
            int j = 0;
            while(j<n){
                if(mp.find(pattern[j])==mp.end() && mp1.find(words[i][j])==mp1.end()){
                    mp[pattern[j]] = words[i][j];
                    mp1[words[i][j]] = pattern[j];
                }
                else{
                    if(mp[pattern[j]]!=words[i][j]) break;
                    if(mp1[words[i][j]]!=pattern[j]) break;
                }
                j++;
            }
            if(j==n) ans.push_back(words[i]);
        }
        return ans;
    }
};