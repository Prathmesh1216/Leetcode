class Solution {
public:
    vector<int> parent,rank;
    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionbr(int u,int v){
        u = findPar(u);
        v = findPar(v);
        if(u==v) return;
        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[u]>rank[v]){
            parent[v] = u;
        }
        else{
            rank[u]++;
            parent[v] = u;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n);
        for(int i = 1;i<n;i++){
            parent[i]  = i;
       }
       map<string,int> mp;
       int i = 0;
       for(auto it : accounts){
           int sz = it.size();
           for(int j = 1;j<sz;j++){
               if(mp.find(it[j])==mp.end()){
                   mp[it[j]] = i;
               }
               else unionbr(i,mp[it[j]]);
           }
           i++;
       }
       map<int,vector<string>> mp1;
       for(auto it : mp){
           int p = findPar(it.second);
           mp1[p].push_back(it.first);
       }
       int k = mp1.size();
       vector<vector<string>> ans(k);
       i = 0;
       for(auto it : mp1){
           ans[i].push_back(accounts[it.first][0]);
           for(auto iit:it.second){
               ans[i].push_back(iit);
           }
           i++;
       }
       return ans;
    }
};