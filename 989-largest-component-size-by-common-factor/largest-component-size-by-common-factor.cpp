class Solution {
public:
    vector<int> parent,size;
    int ans;
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
            ans = max(ans,size[v]);
        }
        else{
            size[u] += size[v];
            parent[v] = u;
            ans = max(ans,size[u]);
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int me = *max_element(nums.begin(),nums.end());
        ans = 1;
        int n = nums.size();
         parent.resize(n);
         size.resize(n,1);
        for(int i = 0;i<n;i++) parent[i] = i;
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++) mp[nums[i]] = i;
        for(int i = 2;i<=me;i++){
            int last = -1;
            for(int j = 1;i*j<=me;j++){
                if(mp.find(i*j)!=mp.end()){
                    if(last==-1) last = mp[i*j];
                    else unionbs(last,mp[i*j]);
                }
            }
        }
        return ans;
    }
};