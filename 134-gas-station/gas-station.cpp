class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            gas[i] -= cost[i];
            sum +=  gas[i];
        }
        if(sum<0) return -1;
        int gc = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            gc += gas[i];
            if(gc<0){
                gc = 0;
                ans = i+1;
            }
        }
        return ans;
    }
};