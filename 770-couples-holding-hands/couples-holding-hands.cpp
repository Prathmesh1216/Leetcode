class Solution {
public:
    vector<int> parent,rank;
    int n;
    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findPar(parent[node]);
    }
    bool unionbr(int u,int v){
        u = findPar(u);
        v = findPar(v);
        if(u==v) return true;
        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[v]<rank[u]){
            parent[v] = u;
        }
        else{
            parent[u] = v;
            rank[v]++;
        }
        return false;
    }
    int minSwapsCouples(vector<int>& row) {
        n = row.size();
        parent.resize(n);
        rank.resize(n);
        for(int i = 0;i<n;i++) parent[i] = i;
        for(int i = 0;i<n;i+=2){
            unionbr(row[i],row[i+1]);
        }
        int ans = 0;
        for(int i = 0;i<n;i+=2){
            if(!unionbr(i,i+1)){
                ans++;
            }
        }
        return ans;

        
    }
};