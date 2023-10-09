class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(auto& it : hand) mp[it]++;
        for(auto& it : mp){
            pq.push({it.first,it.second});
        }
        while(pq.size()>=gs){
            vector<pair<int,int>> rem;
            int sz = gs;
            int last = -1;
            while(sz && !pq.empty()){
                auto [a,f] = pq.top();
                pq.pop();
                if(last==-1) last = a;
                else if(a!=last+1) return false;
                last = a;
                if(f-1>0) rem.push_back({a,f-1});
                sz--;
            } 
            if(sz) return false;
            for(auto& it : rem) pq.push(it);      
        }
        return pq.empty();
    }
};