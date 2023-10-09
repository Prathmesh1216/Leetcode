class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        priority_queue<tuple<int,int ,int>,vector<tuple<int,int,int>>,greater<tuple<int,int ,int>>> pq;
        for(int i = 0;i<nums1.size();i++){
            pq.push(make_tuple(nums1[i]+nums2[0],i,0));
        }
        vector<vector<int>> v;
            while(!pq.empty() && k>0){
            auto [sum,i,j] = pq.top();
            pq.pop();
            v.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size())pq.push({nums1[i]+nums2[j+1],i,j+1});
            k--;
            }
            return v;
        

    }
};