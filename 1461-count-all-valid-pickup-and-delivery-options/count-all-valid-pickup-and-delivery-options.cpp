class Solution {
public:
    // int solve(int p,int d,int n,)
    int countOrders(int n) {
        if(n==1) return 1;
        int a = 2*(n-1)+1;
        long long ans =  (a*(a+1)/2)*1LL*countOrders(n-1);
        return ans%1000000007;
    }
};