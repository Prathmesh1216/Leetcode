class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = accumulate(nums.begin(),nums.end(),0.0);
        for(auto& it : nums) pq.push(it);
        double t = sum;
        int cnt = 0;
        while(t>sum/2){
            double up = pq.top();
            pq.pop();
            t-=(up/2);
            pq.push(up/2);
            cnt++;
        }
        return cnt;
    }
};