class Solution {
public:
    long long dp[100001];
    long long recur(vector<vector<int>>&rides,int nn,int idx)
    {
        if(idx>=nn)
            return 0;
        if(dp[idx]!=-1) return dp[idx];
        int start = idx;
        int end = rides.size()-1;
        int i = rides.size();
        while(start<=end){
            int mid = start + (end-start)/2;
            if(rides[mid][0]>=rides[idx][1]){
                i = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
       // if(i==-1) return dp[idx] = recur(rides,nn,idx+1);
        long long op1=recur(rides,nn,idx+1);
        long long op2=rides[idx][1]-rides[idx][0]+rides[idx][2]+recur(rides,nn,i);
        
        return dp[idx] = max(op1,op2);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        memset(dp,-1,sizeof(dp));
        sort(rides.begin(),rides.end());
        int nn=rides.size();
        
        return recur(rides,nn,0);
    }
};