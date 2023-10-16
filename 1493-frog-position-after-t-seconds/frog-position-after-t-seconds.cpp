class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(t==0 && target==1) return 1;
        if(edges.size()==0 && target==1) return 1;
        if(t>0 && target==1) return 0;
        vector<vector<int>> g(n+1);
        for(auto& it : edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        q.push({1,0});
        int level = 0;
        int tlevel = -1;
        while(!q.empty()){
            int a = q.size();
            while(a--){
                int node = q.front().first;
                int par = q.front().second;
                q.pop();
                if(node==target) tlevel = level;
                for(auto& it : g[node]){
                    if(it==par) continue;
                    q.push({it,node});
                }
            }
            level++;
        }
        level--;
        queue<pair<int,int>> q1;
        q1.push({1,-1});
        vector<double> prob(n+1);
        prob[1] = 1;
       // if(node==1)
        while(!q1.empty()){
            int node = q1.front().first; int par = q1.front().second;
            q1.pop();
            int sz = g[node].size();
            if(node==1){
                for(auto& it : g[node]){
                if(it!=par){
                    prob[it] = prob[node]*(1.0/(sz));
                    q1.push({it,node});
                }
            }
            }
            else{
                for(auto& it : g[node]){
                if(it!=par){
                    prob[it] = prob[node]*(1.0/(sz-1));
                    q1.push({it,node});
                }
            }
            }
            
        }
        cout << level << endl;
        if(t<tlevel) return 0;
        if(t>tlevel && g[target].size()!=1) return 0;
        return prob[target];
    }
};