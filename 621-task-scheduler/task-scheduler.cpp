class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        for(auto& it : tasks){
            v[it-'A']++;
        }
        priority_queue<int> pq;
        for(auto& it : v) if(it) pq.push(it);
        int time = 0;
        while(!pq.empty()){
             vector<int> remaining;
            int cycle = n+1;
            while(cycle && !pq.empty()){
                int mf = pq.top();
                pq.pop();
                if(mf>1) remaining.push_back(mf-1);
                time++;
                cycle--;
            }
            for(auto it : remaining) pq.push(it);
            if(pq.empty()) break;
            time += cycle;

        }
        return time;
    }
};