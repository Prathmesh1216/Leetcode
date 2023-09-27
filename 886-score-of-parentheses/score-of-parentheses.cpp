class Solution {
public:
    int n;
    int solve(string s){
        if(s.size()==2) return 1;
        int o = 0,c = 0;
        int i = 0;
        for(i = 0;i<s.length();i++){
            if(s[i]=='(') o++;
            else{
                c++;
                if(o==c) break;
            }
        }
        int ans2 = 0;
        if(i+1<s.length()) ans2 = solve(s.substr(i+1,s.length()-i-1));
        if(o==1) return 1 + ans2;
        return 2*solve(s.substr(1,i-1)) + ans2;
    }
    int scoreOfParentheses(string s) {
        n = s.length();
        return solve(s);
    }
};