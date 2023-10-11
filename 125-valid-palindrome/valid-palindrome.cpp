class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for(int i = 0;i<s.length();i++){
            if(iswalnum(s[i])) a += tolower(s[i]);
        }
        int i = 0;
        int j = a.length()-1;
        while(i<j){
            if(a[i]!=a[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};