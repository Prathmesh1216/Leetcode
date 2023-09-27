class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long sz = 0;
        int n = s.length();
        for(int i = 0;i<s.length();i++){
            if(isdigit(s[i])){
                sz *= (s[i]-'0');
            }
            else sz++;
        }
        for(int i = n-1;i>=0;i--){
            if(isdigit(s[i])){
                sz /= (s[i]-'0');
                k %= sz;
            }
            else{
                if(k==0 || sz==k) return string(1,s[i]);
                sz--;
            }
        }
        return "";
    }
};