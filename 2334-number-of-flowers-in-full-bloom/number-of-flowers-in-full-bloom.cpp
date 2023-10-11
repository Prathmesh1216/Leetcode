class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(flowers.begin(),flowers.end());
        vector<pair<int,int>> p;
        for(int i = 0;i<people.size();i++){
            p.push_back(make_pair(people[i],i));
        }
        sort(p.begin(),p.end());
        vector<int> ans(m);
        int j = 0;
        for(int i = 0;i<m;i++){
            while(j<n && flowers[j][0]<=p[i].first){
                pq.push(flowers[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top()<p[i].first){
                pq.pop();
            }
            ans[p[i].second] = pq.size();
        }
        return ans;

    }
};