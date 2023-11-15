class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ele(10001);
        vector<int> v;
        for(auto& it : barcodes) ele[it]++;
        priority_queue<pair<int,int>> pq;
        for(int i = 1;i<=10000;i++){
            if(ele[i]>0) pq.push({ele[i],i});
        }
        while(pq.size()>1){
            int a = pq.top().first,e1 = pq.top().second; pq.pop();
            int b = pq.top().first, e2 = pq.top().second; pq.pop();
            v.push_back(e1);
            v.push_back(e2);
            a--;
            b--;
            if(a){
                pq.push({a,e1});
            }
            if(b) pq.push({b,e2});
        }
        if(!pq.empty()) v.push_back(pq.top().second);
        return v;

    }
};