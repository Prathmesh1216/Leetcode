class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> q;
        for(int i = 0;i<queries.size();i++){
            q.push_back(make_pair(queries[i],i));
        }
        sort(q.begin(),q.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int j = 0;
        int n = intervals.size();
        vector<int> ans(queries.size());
        for(int i = 0;i<q.size();i++){
            while(j<n && intervals[j][0]<=q[i].first){
                pq.push(make_pair(intervals[j][1]-intervals[j][0]+1,intervals[j][1]));
                j++;
            }
            while(!pq.empty() && pq.top().second<q[i].first) pq.pop();
            if(pq.empty()) ans[q[i].second] = -1;
            else ans[q[i].second] = pq.top().first;
        }
        return ans;
    }
};