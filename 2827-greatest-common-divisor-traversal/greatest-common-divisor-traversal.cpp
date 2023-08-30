
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int findPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void unionbr(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(rank[u]<rank[v]) {
            parent[u] = v;
        }
        else if(rank[v]<rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    void primeFactors(int val, vector<int>& v) {
        for(int j = 2 ; (j * j) <= val ; j++) {
            bool add = false;
            while((val % j) == 0) {
                val = val / j;
                add = true;
            }
            if(add) {
                v.push_back(j);
            }
        }

        if(val > 1) {
            v.push_back(val);
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n);
        parent.resize(100000);
        rank.resize(100000);
        for(int i = 1;i<100000;i++) parent[i] = i;
        unordered_set<int> st;  
        if(n == 1) {
            return true;
        }
        for(int i = 0 ; i < n; i++) {
            if(nums[i] == 1) {
                return false;
            }
            primeFactors(nums[i], v[i]);
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 1 ; j < v[i].size(); j++) {
                unionbr(v[i][0], v[i][j]);
            }
        }
        for(int i = 0;i<parent.size();i++){
            parent[i] = findPar(parent[i]);
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < v[i].size(); j++) {
                st.insert(parent[v[i][j]]);
            }
        }
        
        
        return st.size() == 1;
    }
};