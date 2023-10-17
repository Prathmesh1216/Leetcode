class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& nd) {
        int sg = nd[0];
        for(int i = 1;i<nd.size();i++){
            sg = gcd(sg,nd[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(sg%nums[i]==0) return i;
        }
        return -1;
    }
};