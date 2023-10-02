class Solution {
public:
    vector<int> parent,size;
    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionbs(int u,int v){
        u = findPar(u);
        v = findPar(v);
        if(u==v) return;
        if(size[u]<size[v]){
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u] += size[v]; 
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0;i<n;i++) parent[i] = i;
        for(auto& it : edges){
            unionbs(it[0],it[1]);
        }
        vector<int> v;
        vector<bool> vis(n);
        long long ans = 0;
        for(int i = 0;i<n;i++){
            if(!vis[findPar(i)]) vis[findPar(i)] = 1,v.push_back(size[findPar(i)]);
        }
        if(v.size()==1 ) return 0;
        long long sum = accumulate(v.begin(),v.end(),0LL);
        for(int i = 0;i<v.size();i++){
            ans += v[i]*1LL*(sum - v[i]);

        }
        return ans/2;

    }
};