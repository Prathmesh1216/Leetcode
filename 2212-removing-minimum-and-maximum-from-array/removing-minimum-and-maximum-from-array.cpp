class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mi = 0;
        int mx = 0;
        int mini = nums[0];
        int maxi = nums[0];
        for(int i = 0;i<n;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                mx = i;
            }
            else if(nums[i]<mini){
                mini = nums[i];
                mi = i;
            }
        }
        if(mi==mx) return min(mi+1,n-mi);
        if(mi<mx){
            return min({mi+1+mx-mi,mi+1+n-mx,n-mi});
        }
        return min({mx+1+mi-mx,mx+1+n-mi,n-mx});
    }
};