class Solution {
public:
    int solve(string& s,char ch){
        int cnt = 0;
        for(int i = 0;i<s.length();i+=2){
            if(s[i]!=ch) cnt++;
        }
        return cnt;
    }
    int minSwaps(string s){
        int n = s.length();
        int c0 = 0,c1 = 0;
        for(auto& it : s) (it=='1')?c1++:c0++;
        if(abs(c1-c0)>1) return -1;
        if(c1>c0) return solve(s,'1');
        if(c0>c1) return solve(s,'0');
        return min(solve(s,'0'),solve(s,'1'));
    }
};