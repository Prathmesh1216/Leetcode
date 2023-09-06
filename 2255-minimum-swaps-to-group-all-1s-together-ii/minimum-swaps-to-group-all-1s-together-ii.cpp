class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int c1 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1) c1++;
        }
        if(c1==0 || c1==1) return 0;
        int i = 0;
        int j = 0;
        int c0 = 0;
        int ans = 123456789;
        nums.insert(nums.end(),nums.begin(),nums.end());
        while(j<nums.size()){
            if(nums[j]==0) c0++;
            if(j-i+1<c1) j++;
            else if(j-i+1==c1){
                ans = min(ans,c0);
                if(nums[i]==0) c0--;
                i++;
                j++;
            }
        }
        return ans;
    }
};