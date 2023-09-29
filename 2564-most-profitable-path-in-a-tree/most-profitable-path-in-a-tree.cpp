class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amt) {
        int n = edges.size()+1;
        vector<int> g[n];
        for(auto &v: edges)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<long> aliceDist(n, 1e9), bobDist(n, 1e9);
        vector<int> par(n);
        par[0] = -1;
        queue<int> q;
        q.push(0);
        int lvl = 0;
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                int cur = q.front();
                q.pop();
                aliceDist[cur] = lvl;
                for(int child: g[cur])
                {
                    if(aliceDist[child]==1e9) q.push(child), par[child] = cur;
                }
            }
            lvl++;
        }
        int b = bob, d = 0;
        while(b!=-1)
        {
            bobDist[b] = d;
            b = par[b];
            d++;
        }
        queue<pair<int, long long>> qq;        
        vector<bool> vis(n);
        qq.push({0, amt[0]});
        vis[0] = true;
        long long ans = INT_MIN;
        while(!qq.empty())
        {
            auto [cur, sum] = qq.front();
            qq.pop();
            bool isEnd = true;
            for(auto child: g[cur])
            {
                if(vis[child]) continue;
                isEnd = false;
                vis[child] = true;
                if(aliceDist[child]<bobDist[child])
                {
                    qq.push({child, sum+amt[child]});
                }
                else if(aliceDist[child]==bobDist[child])
                {
                    qq.push({child, sum+amt[child]/2});
                }
                else{
                    qq.push({child, sum});
                }
            }
            if(isEnd) ans = max(ans, sum);
        }
        return ans;
    }
};
        // for(auto& it : bobpath) cout << it << " ";
        // cout << endl;
        // for(auto& it : bobdist) cout << it << " ";cout << endl;