class Solution {
public:
    map<pair<int,int>,int> mp;
    int solve(int i,int sum,vector<int>& nums){
        if(i==nums.size()){
            if(sum==0) return 0;
            return -123456789;
        }
        if(mp.find({i,sum})!=mp.end()) return mp[{i,sum}];
        return mp[{i,sum}] = max(solve(i+1,sum,nums),nums[i]+ solve(i+1,(sum+nums[i])%3,nums));
    }
    int maxSumDivThree(vector<int>& nums) {
        return solve(0,0,nums);
    }
};