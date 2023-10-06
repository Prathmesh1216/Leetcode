class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;
        while(num2){
            if(num2&1) cnt++;
            num2>>=1;
        }
        int ans = 0;
        for(int i = 31;i>=0;i--){
            if((num1&(1<<i)) && cnt){
                ans|= (1<<i);
                cnt--;
            }
        }
        int i = 0;
        while(cnt>0){
            if((ans&(1<<i))==0){
                ans |= (1<<i);
                cnt--;
            }
            i++;
        }
        return ans;
    }
};