class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        long long cnt = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='0'){
                ans += (cnt*(cnt+1)/2);
                cnt = 0;
            }
            else cnt++;
        }
        if(s[s.length()-1]=='1') ans+= (cnt*(cnt+1)/2);
        return ans%1000000007;
    }
};