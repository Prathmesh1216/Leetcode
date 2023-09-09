class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<vector<int>> as(n,vector<int>(26,0));
        vector<int> v(26);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<words1[i].length();j++){
                as[i][words1[i][j]-'a']++;
            }
        }
        for(int i = 0;i<m;i++){
            vector<int> temp(26);
            for(int j = 0;j<words2[i].length();j++){
                temp[words2[i][j]-'a']++;
            }
            for(int j = 0;j<26;j++){
                v[j] = max(v[j],temp[j]);
            }
        }
        vector<string> ans;
        for(int i = 0;i<n;i++){
            bool flag = true;
            for(int j = 0;j<26;j++){
                if(as[i][j]<v[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(words1[i]);
        }
        return ans;
    }
};