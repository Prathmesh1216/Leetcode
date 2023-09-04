class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int i = 0;
        int j = 0;
        int n = customers.size();
        vector<int> ps(n);
        if(grumpy[0]==0) ps[0] = customers[0];
        for(int i = 1;i<n;i++){
            if(!grumpy[i]) ps[i] = ps[i-1] + customers[i];
            else ps[i] = ps[i-1];
        } 
        int ans = 0;
        int sum = 0;
        while(j<n){
            sum += customers[j];
            if(j-i+1==k){
                if(i>0) ans = max(ans,ps[i-1] + sum + ps[n-1]-ps[j]);
                else ans = max(ans,sum+ps[n-1]-ps[j]);
                sum-=customers[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};