class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq;
        priority_queue<int,vector<int>,greater<int>> pq1;
        int n = costs.size();
        int i = 0;
        while(i<candidates){
            pq.push(costs[i]);
            i++;
        }
        i--;
        int j = 0;
        while(n-1-j!=i && j<candidates){
            pq1.push(costs[n-1-j]);
            j++;
        }
        i++;
        cout << i << " " << j << endl;
        long long ans = 0;
        while(k--){
            if(pq.size()>0 && pq1.size()>0 && pq.top()<=pq1.top()){
                ans += pq.top();
                pq.pop();
                if(i<=n-1-j) pq.push(costs[i]),i++;
            }
            else if(pq.size()>0 && pq1.size()>0 && pq.top()>pq1.top()){
                ans += pq1.top();
                pq1.pop();
                if(i<=n-1-j) pq1.push(costs[n-1-j]),j++;
            }
            else if(pq.size()>0){
                ans += pq.top();
                pq.pop();
            }
            else if(pq1.size()>0){
                ans += pq1.top();
                pq1.pop();
            }
        }
        return ans;
    }
};