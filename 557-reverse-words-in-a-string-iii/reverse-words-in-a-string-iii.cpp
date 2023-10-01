class Solution {
public:
    string reverseWords(string s) {
        string ans  = "";
        int i = 0;
        string temp = "";
        while(i<s.length()){
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans += temp + " ";
                temp = "";
            }
            else temp += s[i];
            i++;

        }
        reverse(temp.begin(),temp.end());
                ans += temp;
                temp = "";
                return ans;

    }
};