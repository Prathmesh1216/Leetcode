class Solution {
public:
    #define mp make_pair
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        vector<vector<pair<int,int>>> g(n);
        for(auto& it : meetings){
            g[it[0]].push_back(mp(it[1],it[2]));
            g[it[1]].push_back(mp(it[0],it[2]));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,fp});
        pq.push({0,0});
        set<int> know;
        while(!pq.empty()){
            int node = pq.top().second, time = pq.top().first;
            pq.pop();
            if(know.find(node)!=know.end()) continue;
            know.insert(node);
            for(auto& it : g[node]){
                if(time<=it.second){
                    pq.push({it.second,it.first});
                }
            }
        }
        vector<int> ans(know.begin(),know.end());
        return ans;
    }
};