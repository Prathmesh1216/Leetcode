class Solution {
public:
    long long solve(long long n){
        if(n<+0) return 123456789;
        if(n==1) return 0;
        if(n&1) return 1 +  min(solve(n+1),solve(n-1));
        return 1+solve(n/2);
    }
    int integerReplacement(int n) {
        return solve(n);
    }
};