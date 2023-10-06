class Solution {
public:
    vector<int> vt;
    bool isValid(vector<int>& v){
        for(int i = 0;i<52;i++){
            if(vt[i]>v[i]) return false; 
        }
        return true;
    }
    string minWindow(string s, string t) {
        vt.resize(52);
        for(auto& it : t){
            if(isupper(it)){
                vt[26 + (it-'A')]++;
            }
            else vt[it-'a']++;
        } 
        vector<int> v(52);
        int i = 0;
        int j = 0;
        int ans = 123456789;
        int ai = 0;
        int aj = 0;
        while(j<s.length()){
            if(isupper(s[j])){
                v[26+(s[j]-'A')]++;
            }
            else v[s[j]-'a']++;
            while(isValid(v)){
                if(j-i+1<ans){
                    ans  = j-i+1;
                    ai = i;
                    aj = j;
                }
                if(isupper(s[i])){
                    v[26+(s[i]-'A')]--;
                }
                else v[s[i]-'a']--;
                i++;
            }
            j++;
        }
        if(ans==123456789) return "";
        return s.substr(ai,aj-ai+1);
    }
};