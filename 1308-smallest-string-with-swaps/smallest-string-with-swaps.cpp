class Solution {
public:
    vector<int> parent,rank;
    int findPar(int node){
        if(parent[node] == node) return node;
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        map<int,multiset<char>> mp;
        int n = s.length();
        parent.resize(n);rank.resize(n);
        for(int i  = 1;i<n;i++) parent[i] = i;
        for(auto& it : pairs){
            unionbr(it[0],it[1]);
        }
        for(int i = 0;i<n;i++){
            mp[findPar(i)].insert(s[i]);
        }
        for(int i = 0;i<n;i++){
            auto it = mp[findPar(i)].begin();
            s[i] = *it;
            mp[findPar(i)].erase(it);
        }
        return s;
    }
};