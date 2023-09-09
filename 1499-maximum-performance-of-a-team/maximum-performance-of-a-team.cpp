class Solution {
public:
    static bool cmp(pair<int,int>& p1,pair<int,int>& p2){
        return p1.second>p2.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++){
            v.push_back(make_pair(speed[i],efficiency[i]));
        }
        sort(v.begin(),v.end(),cmp);
        long long ans = 0;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum += v[i].first;
            pq.push(v[i]);
            ans = max(ans,v[i].second*sum);
            if(pq.size()==k){
                sum = sum - (pq.top().first);
                pq.pop();
            }
        }
        return ans%1000000007;
    }
};