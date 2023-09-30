class Solution {
public:
long long cnt=1;
    long long f(int node,vector<int> &vis,vector<int> adj[],int k,vector<int> &values){
        vis[node]=1;
        long long total=0;
        for(auto it:adj[node]){
            
            if(!vis[it]) {
               long long a=f(it,vis,adj,k,values);
               if(a%k==0) cnt++;
                else total+=a*1LL;
            }
            
            
        }
        return total+1LL*values[node];
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        long long sum=accumulate(values.begin(),values.end(),0*1LL);
       
        vector<int> vis(n,0);
        f(0,vis,adj,k,values);
        return cnt;

        
    }
};