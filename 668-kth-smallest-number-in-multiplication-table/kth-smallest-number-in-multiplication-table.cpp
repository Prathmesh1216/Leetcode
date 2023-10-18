class Solution {
public:
    int elements(int m,int n,int num){
        return min(n,num/m);
    }
    int calc(int m,int n,int mid){
        int ans = 0;
        for(int i = 1;i<=m;i++){
            ans += elements(i,n,mid);
        }
        return ans;
    }
    int findKthNumber(int m, int n, int k) {
        int start = 1;
        int end = 1e9;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(calc(m,n,mid)>=k){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};