class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        bool flag = false;
        if(x<0) x = abs(x),flag = true; 
        while(x>0){
            ans = (ans*10 + x%10);
            x/=10;
        }
        if(flag) ans = -ans;
        if(ans<INT_MIN || ans>INT_MAX) return 0;
        return ans;
    }
};