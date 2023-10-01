class Solution {
public:
    vector<int> parent,size;
    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionbs(int u,int v,int& cnt){
        u = findPar(u);
        v = findPar(v);
        if(u==v) return;
        if(size[u]<size[v]){
            cnt--;
            size[v] += size[u];
            parent[u] = v;
        }
        else{
            cnt--;
            size[u] += size[v];
            parent[v] = u;
        }
    }
    int findCircleNum(vector<vector<int>>& ic) {
        int n = ic.size();
        parent.resize(n);size.resize(n,1);
        for(int i = 0;i<n;i++) parent[i] = i;
        int cnt = n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i!=j && ic[i][j]==1) unionbs(i,j,cnt);
            }
        }
        return cnt;
    }
};