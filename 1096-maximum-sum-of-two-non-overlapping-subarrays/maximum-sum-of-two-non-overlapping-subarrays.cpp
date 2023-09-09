class Solution {
public:
    int n;
    vector<int> ps;
    int maxsubarray(int i,int j,vector<int>& nums,int len){
        if(i<0 || j>=n) return 0;
        if(j-i+1<len) return 0;
        int k = i;
        int ans = 0;
        while(k<=j){
            if(k-i+1==len){
                ans = max(ans,ps[k]-ps[i]+nums[i]);
                i++;
            }
            k++;
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        n = nums.size();
        ps.resize(n);
        ps[0] = nums[0];
        for(int i = 1;i<n;i++){
            ps[i] = ps[i-1] + nums[i];
        }
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<n){
            if(j-i+1==firstLen){
                ans = max(ans,ps[j]-ps[i]+nums[i]+max(maxsubarray(0,i-1,nums,secondLen),maxsubarray(j+1,n-1,nums,secondLen)));
                i++;
            }
            j++;
        }
        return ans;
    }
};