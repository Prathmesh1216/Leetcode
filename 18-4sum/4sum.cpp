class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
       // vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int k = j+1;
                int l = n-1;
                long long tar = target - 1LL*nums[i] - 1LL*nums[j];
                while(k<l){
                    long long sum = nums[k] + nums[l];
                    if(sum==tar){ 
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++,l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<tar) k++;
                    else l--;
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};