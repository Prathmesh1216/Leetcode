class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]) return a[2]<b[2];
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),cmp);
        int n = trips.size();
        int pc = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0;i<n;i++){
            while(!pq.empty() && pq.top().first<=trips[i][1]){
                pc-=pq.top().second;
                pq.pop();
            }
            pq.push({trips[i][2],trips[i][0]});
            pc+=trips[i][0];
            if(pc>capacity) return false;
        }
        return true;
    }
};