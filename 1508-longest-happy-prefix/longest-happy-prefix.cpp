class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        if(n==1) return "";
        vector<int> p(n);
        int i = 0,j = 1;
        while(j<n){
            if(s[i]==s[j]){
                p[j] = i+1;
                i++;
                j++;
            }
            else{
                if(i==0) j++;
                else i = p[i-1];
            }
        }
        return s.substr(0,i);
    }
};