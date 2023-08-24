class Solution {
public:
    static bool cmp(string& a,string& b){
        if(a.length()==b.length()) return a>b;
        return a.length()<b.length();
    }
    bool isValid(string& a,vector<vector<int>>& v){
        int j = 0;
        for(int i = 0;i<v.size();i++){
            if(v[i][a[j]-'a']>0) j++;
             if(j==a.length()) return true;
        }
        if(j==a.length()) return true;
        return false;
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int> u;
        for(int i=0;i<words.size();i++){
            u[words[i]]++;
        }
        
        for(int i=words.size()-1;i>=0;i--){
            string t=words[i];
            while(t!=""){
                if(u[t]!=0){
                    t.pop_back();
                }
                else{
                    break;
                }
            }
            if(t==""){
                return words[i];
            }
        }
        return "";
    }
};