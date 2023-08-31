class Solution {
public:
    int solve(int n){
        int ans = 0;
        int a = n;
        for(int i = 2;i<=sqrt(a);i++){
            while(n%i==0){
                ans += i;
                n /= i;
            }
        }
        if(n>1) ans+=n;
        return ans;

    }
    int smallestValue(int n) {
        while(solve(n)!=n){
            n = solve(n);
        }
        return n;
    }
};