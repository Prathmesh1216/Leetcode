class Solution {
public:
    void solve(vector<int>& lps,string& s){
        int i = 0;
        int j = 1;
        while(j<s.length()){
            if(s[i]==s[j]){
                i++;
                lps[j] = i;
                j++;
            }
            else{
                if(i==0) j++;
                else i = lps[i-1];
            }

        }

    }
    string shortestPalindrome(string& s) {
        string t = s;
        reverse(t.begin(),t.end());
        string a = s+"$"+t;
        vector<int> lps(a.length());
        solve(lps,a);
        int i = lps[a.length()-1];
        string temp = s.substr(i);
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};