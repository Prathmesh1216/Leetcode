class Solution {
public:
    bool isPalindrome(int mask,string& s){
        string ans = "";
        for(int i = 0;i<s.length();i++){
            if(mask&(1<<i)) ans+= s[i];
        }
        int i = 0;
        int j = ans.length()-1;
        while(i<j){
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }
        return true;
    }
   // int dp[13][1<<13][1<<13][13][13];
    int solve(int i,int mask1,int mask2,int len1,int len2,string& s){
        if(i==s.length()){
            if(isPalindrome(mask1,s) && isPalindrome(mask2,s)) return len1*len2;
            return 0;
        }
        return max({solve(i+1,mask1|(1<<i),mask2,len1+1,len2,s),solve(i+1,mask1,mask2|(1<<i),len1,len2+1,s),solve(i+1,mask1,mask2,len1,len2,s)});
    }
    int maxProduct(string s) {
        return solve(0,0,0,0,0,s);
    }
};