class Solution {
public:
    vector<int> parent,rank,minscore;
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
        else if(rank[v]<rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 1;i<=n;i++) parent[i] = i;
        minscore.resize(n+1,123456789);
        for(auto& it : roads){
            unionbr(it[0],it[1]);
            int s1 = minscore[findPar(it[0])];
            int s2 = minscore[findPar(it[1])];
            unionbr(it[0],it[1]);
            minscore[findPar(it[0])] = min({s1,s2,it[2]});
            minscore[findPar(it[1])] = min({s1,s2,it[2]});
        }
        int ans = 123456789;
        for(int i = 1;i<=n;i++){
            if(findPar(i)==findPar(1)) ans = min(ans,minscore[i]);
        }
        return ans;
    }
};