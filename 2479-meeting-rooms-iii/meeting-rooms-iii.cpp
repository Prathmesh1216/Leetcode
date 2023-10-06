class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> ans(n);
        set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        int time = 0;
        for(int i = 0;i<meetings.size();i++){
            while(!pq.empty() && pq.top().first<=meetings[i][0]){
                st.insert(pq.top().second);
                pq.pop();
            }
            if(st.empty()){
                long long t = pq.top().first + meetings[i][1] - meetings[i][0];
                int ind = pq.top().second;
                ans[ind]++;
                pq.pop();
                pq.push({t,ind});
            }
            else{
                ans[*st.begin()]++;
                pq.push({meetings[i][1],*st.begin()});
                st.erase(st.begin());
            }
        }
        int as = 0;
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(ans[i]>as){
                idx = i;
                as = ans[i];
            }
        }
        return idx;
    }
};