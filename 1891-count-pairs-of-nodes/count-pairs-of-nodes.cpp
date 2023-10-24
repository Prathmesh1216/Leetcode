class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        int m = edges.size();
        map<pair<int,int>,int> mp;
        vector<int> indegree(n+1);
        for(int i = 0;i<m;i++){
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            if(edges[i][1]<edges[i][0]) swap(edges[i][0],edges[i][1]);
            mp[{edges[i][0],edges[i][1]}]++;
        }
        vector<int> v = indegree;
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto& it : queries){
            int cnt = 0;
            int i = 1;
            int j = n;
            while(i<j){
                if(v[i]+v[j]>it){
                    cnt += (j-i);
                    j--;
                }
                else i++;
            }
            for(auto& iit: mp){
                if ( (indegree[iit.first.first] + indegree[iit.first.second] > it) &&
                     (indegree[iit.first.first] + indegree[iit.first.second] - iit.second <= it)) {
                    cnt--;
                }
            }
            ans.push_back(cnt);

        }
        return ans;
    }
};