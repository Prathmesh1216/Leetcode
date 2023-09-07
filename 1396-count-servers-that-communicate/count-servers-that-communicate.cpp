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
        if(u==v){
           return;
        }
        else if(size[v]<size[u]){
            parent[v] = u;
            size[u]+=size[v];
            size[v] = 1;
        }
        else{
            parent[u] = v;
           size[v]+=size[u];
           size[u] = 1;
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        parent.resize(n*m);
        size.resize(n*m,1);
        for(int i = 0;i<n*m;i++){
            parent[i] = i;
        }
     //   vector<int> row,col;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    int node = i*m+j;
                    while(j<m){
                        if(grid[i][j]==1){
                            unionbs(node,i*m+j);
                        }
                        j++;
                    }
                }
            }
        }
        for(int j = 0;j<m;j++){
            for(int i = 0;i<n;i++){
                if(grid[i][j]){
                    int node = i*m+j;
                    while(i<n){
                        if(grid[i][j]){
                            unionbs(node,i*m+j);
                        }
                        i++;
                    }
                }
            }
        
        }
     //   for(auto it : size) cout << it << endl;

        int ans = 0;
        for(int i = 0;i<size.size();i++){
            if(size[i]>1) ans += size[i];

        }
        return ans;
    }
};