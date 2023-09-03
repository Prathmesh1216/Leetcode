class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt=0;
         int a=target;
         if(startValue>target) return startValue-target;
         while( target!=startValue){
             if(target<startValue) return startValue-target+cnt;
             if(target%2==0) target/=2;
             else target+=1;
             cnt++;
         }
         return cnt;
    }
};