class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> mp;
        for(int i = 0;i<messages.size();i++){
            int cnt = 0;
            for(int j = 0;j<messages[i].length();j++){
                if(messages[i][j]==' ') cnt++;
            }
            mp[senders[i]] += (cnt+1);
        }
        string ans = "";
        int fq = 0;
        for(auto& it : mp){
            if(it.second>fq){
                fq = it.second;
                ans = it.first;
            }
            else if(fq==it.second){
                ans = max(ans,it.first);
            }
        }
        return ans;
    }
};