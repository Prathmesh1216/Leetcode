class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int cnt = 0;
        bool flag = true;
        while(n){
            if(n&1){
                if(flag) cnt++;
                else return false;
            }
            n=n>>1;
            flag = !flag;
        }
        return cnt==1;
    }
};