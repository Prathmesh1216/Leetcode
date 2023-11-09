class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        char last = s[0];
        long long cnt = 1;
        const int m = 1e9+7;
        for(int i = 1;i<s.length();i++){
            if(s[i]!=last){
                ans += (cnt*(cnt+1)/2)%m;
                last = s[i];
                cnt = 1;
            }
            else cnt++;
        }
        ans += (cnt*(cnt+1)/2)%m;
        return ans;
    }
};