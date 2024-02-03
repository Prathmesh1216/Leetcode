class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n =  arr.size();
        int dp[n+1];
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int len = 0;
            int maxi = INT_MIN;
            int maxans = INT_MIN;
            for(int j = i;j<(min(i+k,n));j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = len*maxi + dp[j+1];
                maxans = max(sum,maxans);
            }
            dp[i] = maxans;
        }
        return dp[0];
    }
};