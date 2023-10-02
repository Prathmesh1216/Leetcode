class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        int ans = -123456789;
        vector<priority_queue<int,vector<int>,greater<int>>> v(n);
        for(auto& it : edges){
            v[it[0]].push(vals[it[1]]);
            v[it[1]].push(vals[it[0]]);
            if(v[it[0]].size()>k) v[it[0]].pop();
            if(v[it[1]].size()>k) v[it[1]].pop();
        }
        for(int i = 0;i<n;i++){
            int sum = 0;
            while(!v[i].empty()){
                if(v[i].top()>0) sum += v[i].top();
                v[i].pop();
            }
            sum += vals[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};