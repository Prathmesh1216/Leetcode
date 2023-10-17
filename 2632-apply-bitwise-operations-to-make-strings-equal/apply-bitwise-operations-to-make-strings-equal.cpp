class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int s1 = 0;
        int d1 = 0,s0 = 0,d0 = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='1'){
                if(s[i]==t[i]) s1++;
                else d1++;
            }
            else{
                if(s[i]==t[i]) s0++;
                else d0++;
            }
        }
        for(int i = 0;i<s.length();i++){
            if(s[i]==t[i]) continue;
            if(s[i]=='1'){
                if(s1==0 && d0==0) return false;
            }
            else{
                if(s1==0 && d1==0) return false;
            }
        }
        return true;
    }
};