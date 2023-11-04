class Solution {
public:
    bool isValid(int mid,int m,int n,int k){
        int cnt  = 0;
        for(int i = 1;i<=m;i++){
            int a = mid/i;
            if(a>n) a = n;
            cnt += a;
        }
        return cnt>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int start = 1;
        int end = m*n;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,m,n,k)){
                ans = mid ;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};