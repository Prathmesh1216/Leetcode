class Solution {
public:
    int n;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        n=nums.size();
        vector<int> dist(n);
        int maxi = -123456789;
        for(int i = 0;i<n;i++){
            dist[i] = nums[i];
        }
        dist[0] = nums[0];
        priority_queue<pair<int,int>> pq;
        pq.push({dist[0],0});
        for(int i = 1;i<n;i++){
            while(!pq.empty() && pq.top().second<i-k) pq.pop();
            if(!pq.empty()) dist[i] = max(dist[i],nums[i]+pq.top().first);
            pq.push({dist[i],i});
        }
        return *max_element(dist.begin(),dist.end());
    }
};