class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 1;
        int n = nums.size();
        while(j<n){
            vector<int> temp;
            int sz = 1;
            temp.push_back(nums[i]);
            while(j < n && nums[j]-nums[i]<=k && sz<3){
                temp.push_back(nums[j]);
                j++;
                sz++;
            }
            if(sz!=3) return {};
            i = j;
            j++;
            ans.push_back(temp);
        }
        return ans;

    }
};