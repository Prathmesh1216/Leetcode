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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0;i<n;i++) parent[i] = i;
        vector<int> indegree(n);
        vector<int> vis(n);
        for(auto& it : edges){
            unionbs(it[0],it[1]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        for(int i = 0;i<n;i++) parent[i] = findPar(i);
        set<int> st(parent.begin(),parent.end());
        int tc = st.size();
        for(int i = 0;i<n;i++){
            if(indegree[i]!=size[findPar(i)]-1 && !vis[findPar(i)]){
                vis[findPar(i)] = 1;
                tc--;
            }
        }
        return tc;
    }
};