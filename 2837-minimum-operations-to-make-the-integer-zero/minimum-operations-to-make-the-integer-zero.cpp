class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int x = 0;x<=60;x++){
            long temp = (long)(num1-(long)x*num2);
            if(temp<0) break;
            vector<long> v;
            for(int k = 0;k<=61;k++){
                if(((1l<<k) & temp) != 0){
                    v.push_back(1l<<k);
                }
            }
            long sum = 0l;
            for(long num : v) sum += num;
            if(v.size()<=x && sum>=x) return x; 
        }
        return -1;

    }
};