class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        long long cnt = 0;
        for(int i = 0;i<s.length();i++){
            if(i!=0 && s[i]!=s[i-1]){
                ans += (cnt*(cnt+1)/2);
                cnt = 0;
            }
            cnt++;

        }
        ans += (cnt*(cnt+1)/2);
        return ans%1000000007;
    }
};