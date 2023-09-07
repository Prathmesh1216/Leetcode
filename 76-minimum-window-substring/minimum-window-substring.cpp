class Solution {
public:
    bool isValid(vector<int>& v1,vector<int>& v){
        for(int i = 0;i<52;i++){
            if(v1[i]<v[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> v(52,0);
        int ans = 123456789;
        int tar = 0;
        for(int i = 0;i<t.length();i++){
            if(isupper(t[i])){
                if(v[26 +(t[i]-'A')]==0) tar++;
                v[26 +(t[i]-'A')]++;
            }
            else{
                if(v[t[i]-'a']==0) tar++;
                v[t[i]-'a']++;
            } 
        }
        vector<int> v1(52,0);
        int i = 0;
        int j = 0;
        int st, e;
        while(j<s.length()){
            if(isupper(s[j])){
                v1[26 +(s[j]-'A')]++;
            }
            else{
                v1[s[j]-'a']++;
            } 
            while(isValid(v1,v) && i<=j){
                if(j-i+1<ans){
                    ans = j-i+1;
                    st = i;
                    e = j;
                }
                if(isupper(s[i])){
                    if(v1[26 +(s[i]-'A')]>0) v1[26 +(s[i]-'A')]--;
                }
                else{
                    if(v1[s[i]-'a']>0) v1[s[i]-'a']--;
                } 
                i++;
            }
            j++;
        }
        if(ans==123456789) return "";
        return s.substr(st,e-st+1);

    }
};