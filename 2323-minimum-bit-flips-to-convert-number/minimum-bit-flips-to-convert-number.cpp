class Solution {
public:
    int minBitFlips(int start, int end) {
        int cnt = 0;
        for(int i = 0;i<32;i++){
            if((start&(1<<i)) != (end&(1<<i))) cnt++;
        }
        return cnt;
    }
};