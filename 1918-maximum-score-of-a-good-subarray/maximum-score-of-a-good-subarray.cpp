class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int cmin = nums[k];
        int i = k;
        int j = k;
        int cs = 1;
        int ans = nums[k];
        while(i>0 || j<n-1){
            if(j+1<n && i-1>=0 && nums[j+1]>nums[i-1]){
                cs++;
                j++;
                cmin = min(cmin,nums[j]);
                ans = max(ans,cmin*cs);
            }
            else if(i-1>=0 && j+1< n &&  nums[i-1]>nums[j+1]){
                i--;
                cs++;
                cmin = min(cmin,nums[i]);
                ans = max(ans,cmin*cs);
            }
            else if(i-1>=0 && j+1<n && nums[i-1]==nums[j+1]){
                cs+=2;
                j++;
                i--;
                cmin = min(cmin,nums[i]);
            }
            else if(i-1>=0){
                cs++;
                i--;
                cmin = min(cmin,nums[i]);
            }
            else if(j+1<n){
                cs++;
                j++;
                cmin = min(cmin,nums[j]);
            }
            ans = max(ans,cmin*cs);
        }
        return ans;
    }
};