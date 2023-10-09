class Solution {
public:
    int minJumps(vector<int>& arr) {
       int n = arr.size();
       vector<int> adj[n];
       map<int,vector<int>> mp;
       for(int i = 0;i<n;i++){
           mp[arr[i]].push_back(i);
       }
       queue<pair<int,int>> q;
       vector<bool> vis(n);
       vis[0] = 1;
       q.push({0,0});
       while(!q.empty()){
           int node = q.front().first;
           int dist = q.front().second;
           q.pop();
           if(node==n-1) return dist;
           if(node+1<n && !vis[node+1]) vis[node+1] = 1,q.push({node+1,dist+1});
            if(node-1>=0 && !vis[node-1]) vis[node-1] = 1,q.push({node-1,dist+1});
           for(auto& it : mp[arr[node]]){
               if(!vis[it]) vis[it] = 1,q.push({it,dist+1});
           }
           mp[arr[node]].clear();
       }
       return -1;
    }
};