class Solution {
public:

    double maxAverageRatio(vector<vector<int>>& classes, int es) {
        int n = classes.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto& it : classes){
            pq.push({1.0*(it[0]+1)/(it[1]+1) - 1.0*it[0]/it[1],{it[0],it[1]}});
        }
        while(es>0){
            auto it = pq.top();
            pq.pop();
            int a = it.second.first;
            int b = it.second.second;
            a++;
            b++;
            pq.push({1.0*(a+1)/(b+1) - 1.0*a/b,{a,b}});
            es--;
        }
        double ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans += (1.0*it.second.first/it.second.second);
        }
        return ans/n;
        
    }
};