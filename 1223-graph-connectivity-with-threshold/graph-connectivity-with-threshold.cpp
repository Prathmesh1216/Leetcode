class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionbr(int u,int v){
        u = findPar(u);
        v = findPar(v);
        if(rank[u]<rank[v]) parent[u] = v;
        else if(rank[v]<rank[u]) parent[v] = u;
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 1;i<=n;i++) parent[i] = i;
        for(int i = 1;i<=n;i++){
            if(i>threshold){
                for(int j = 2;i*j<=n;j++){
                    unionbr(i,i*j);
                }
            }
        }
        for(int i = 1;i<=n;i++){
            parent[i] = findPar(i);
        }
        vector<bool> ans;
        for(auto it : queries){
            if(parent[it[0]]==parent[it[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};