class Solution {
public:
    vector<int> rank,parent;
    bool isSimilar(string& a,string& b){
        int cnt = 0; int i1 = -1,i2 = -1;
        for(int i = 0;i<a.length();i++){
            if(a[i]!=b[i]){
                cnt++;
                if(i1!=-1) i2 = i;
                else i1 = i;
            }
        }
        if(cnt==0) return true;
        if(cnt==1 || (cnt>2)) return false;
        if(a[i1]!=b[i2] || a[i2]!=b[i1]) return false;
        return true;
    }
    int findPar(int node){
        if(parent[node]==node) return node;
        return findPar(parent[node]);
    }
    void unionbr(int u,int v){
        u = findPar(u), v = findPar(v);
        if(u==v) return;
        if(rank[u]<rank[v]) parent[u] = v;
        else if(rank[v]<rank[u]) parent[v] = u;
        else parent[u] = v, rank[v]++;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n); rank.resize(n);
        for(int i = 1;i<n;i++) parent[i] = i;
        for(int i = 0;i<strs.size();i++){
            for(int j = i+1;j<strs.size();j++) if(isSimilar(strs[i],strs[j])) unionbr(i,j);
        }
        set<int> st;
        for(int i = 0;i<n;i++) st.insert(findPar(i));
        return st.size();
    }
};