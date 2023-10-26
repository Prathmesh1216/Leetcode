class Solution {
public:
    #define pii pair<int,int>
    bool inr(int n){
        if(n>=0 && n<=1000) return true;
        return false;
    }
    int minimumOperations(vector<int>& nums, int start, int target) {
        queue<pii> q;
        q.push({start,0});
        vector<int> vis(1001);
        vis[start] = 1;
        while(!q.empty()){
            int node = q.front().first;int steps = q.front().second; q.pop();
            if(node==target) return steps;
            if(node<0 || node>1000) continue;
            for(int i = 0;i<nums.size();i++){
                if(inr(nums[i]+node) && !vis[nums[i]+node]){
                    vis[nums[i]+node] = 1;
                    q.push({nums[i]+node,steps+1});
                }
                if(inr(-nums[i]+node) && !vis[-nums[i]+node]){
                    vis[-nums[i]+node] = 1;
                    q.push({-nums[i]+node,steps+1});
                }
                if(inr(nums[i]^node) && !vis[nums[i]^node]){
                    vis[nums[i]^node] = 1;
                    q.push({nums[i]^node,steps+1});
                }
                if(!inr(nums[i]+node) && (nums[i]+node) ==target) return steps+1;
                if(!inr(-nums[i]+node) && (node-nums[i])==target) return steps+1;
                if(!inr(nums[i]^node) && (nums[i]^node) == target) return steps+1;
            }
        }
        return -1;
    }
};