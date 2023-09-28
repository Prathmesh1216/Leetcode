class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(auto& it : nums){
            if(it&1) ans.push_back(it);
            else ans.insert(ans.begin(),it);
        }
        return ans;
    }
};