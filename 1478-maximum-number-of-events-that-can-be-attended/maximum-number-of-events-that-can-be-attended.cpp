class Solution {
public:
    int n;
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(),events.end(),cmp);
        int ans = 0;
        int i = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int d = 1;d<=100000;d++){
            while(!pq.empty() && pq.top()<d) pq.pop();
            while(i<n && events[i][0]==d){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            if(pq.empty() && i==n) break;
        }
        return ans;
    }
};