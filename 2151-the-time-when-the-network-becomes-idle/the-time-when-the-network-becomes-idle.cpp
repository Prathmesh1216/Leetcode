class Solution {
public:
    #define pb push_back
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
        int n = pat.size();
        vector<vector<int>> g(n);
        for(auto& it : edges){
            g[it[0]].pb(it[1]);
            g[it[1]].pb(it[0]);
        }
        vector<int> time(n,123456789);
        time[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& it : g[node]){
                if(time[node]+1<time[it]){
                    time[it] = 1 + time[node];
                    q.push(it);
                }
            }
        }
        for(auto& it : time) it*=2;
        int ans = 0;
        for(int i = 1;i<n;i++){
            int lastmsg = ((time[i]-1)/pat[i])*pat[i];
            lastmsg += time[i];
            ans = max(ans,lastmsg+1);
        }
        return ans;

        return 1;
    }
};