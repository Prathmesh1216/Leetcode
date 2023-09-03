class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int n = profit.size();
        for(int i = 0;i<n;i++){
            v.push_back({profit[i],difficulty[i]});
        }
        sort(v.begin(),v.end(),cmp);
        sort(worker.rbegin(),worker.rend());
        int i = 0;
        int j = 0;
        int m = worker.size();
        int ans  =0;
        while(i<n && j<m){
            if(worker[j]>=v[i].second){
                ans += v[i].first;
                j++;
            }
            else{
                while(worker[j]<v[i].second){
                    i++;
                }
            }
        }
        return ans;
    }
};