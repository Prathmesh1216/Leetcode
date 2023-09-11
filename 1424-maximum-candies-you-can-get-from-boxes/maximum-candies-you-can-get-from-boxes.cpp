class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        long long ans = 0;
        vector<int> vis(n);
        queue<int> q;
        for(int i = 0;i<initialBoxes.size();i++){
            int it = initialBoxes[i];
            q.push(it);
        }
        while(!q.empty()){
            int node = q.front();
           // cout << node << endl;
            q.pop();
            if(vis[node]) continue;
            if(candies[node]==0) continue;
            vis[node] = 1;
            for(auto j:containedBoxes[node])
            {
                if(vis[j])
                continue;
                q.push(j);
            }
            for(int j=0;j<keys[node].size();j++)
            {
                status[keys[node][j]]=1;
            }
    
        }
        for(int j = 0;j<n;j++){
            if(vis[j] && status[j]==1){
                ans += candies[j];
            }
        }
        return ans;

    }
};