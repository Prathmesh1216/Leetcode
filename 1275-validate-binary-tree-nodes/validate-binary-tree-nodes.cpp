class Solution {
public:
    vector<int> parent,size;
    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findPar(parent[node]);
    }
    bool unionbs(int u,int v){
        u = findPar(u);
        v = findPar(v);
        if(u==v) return true;
        if(size[u]<size[v]){
            parent[u] = v;
            size[v]+=size[u];
        }
        else{
            size[u]+=size[v];
            parent[v] = u;
        }
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        vector<int> indegree(n);
        parent.resize(n),size.resize(n,1);
        for(int i = 0;i<n;i++) parent[i] = i;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(lc[i]!=-1){
                indegree[lc[i]]++;
            }
            if(rc[i]!=-1){
                indegree[rc[i]]++;
            }
        }
        for(int i = 0;i<n;i++){
            if(indegree[i]==0) cnt++;
            if(indegree[i]>1) return false;
        }
        for(int i = 0;i<n;i++){
            if(lc[i]!=-1){
                if(unionbs(i,lc[i])) return false;
            }
            if(rc[i]!=-1) if(unionbs(i,rc[i])) return false;
        }
        return cnt==1;
    }
};