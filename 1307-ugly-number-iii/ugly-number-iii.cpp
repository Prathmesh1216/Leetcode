class Solution {
public:
    bool isValid(long long mid,long long n,long long a,long long b,long long c){
        long long cnt = floor(mid/a) + floor(mid/b) + floor(mid/c) - floor(mid/lcm(a,b)) -floor(mid/lcm(b,c)) - floor(mid/lcm(a,c)) + floor(mid/lcm(a,lcm(b,c)));
        return cnt>=n;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long start = 0;
        long long end = 2e9;
        long long ans = -1;
        while(start<=end){
            long long mid = start + (end-start)/2;
            if(isValid(mid,n,a,b,c)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};