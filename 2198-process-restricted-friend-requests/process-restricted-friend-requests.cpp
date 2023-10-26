class Solution {
public:
    #define pii pair<int,int>
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
            parent[v] = u;
            rank[u]++;
        }
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        parent.resize(n),rank.resize(n);
        for(int i = 1;i<n;i++) parent[i] = i;
        int i = 0;
        vector<bool> ans(requests.size());
        for(auto& it : requests){
            int u = it[0],v = it[1];
            int pu = findPar(u),pv = findPar(v);
            bool flag = true;
            for(auto& iit : restrictions){
                if((findPar(iit[0])==pu && findPar(iit[1])==pv) || (findPar(iit[0])==pv && findPar(iit[1])==pu)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                unionbr(u,v); ans[i] = 1;
            }
            i++;
        }
        return ans;

    }
};