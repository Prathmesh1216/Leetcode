class Solution {
public:
    bool isValid(int mid,vector<int>& nums,int n){
        int cnt = 0;
        for(auto& it : nums){
            cnt += (it/mid + (it%mid!=0));
        }
        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start= 1;
        int end = 1e5;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,quantities,n)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};