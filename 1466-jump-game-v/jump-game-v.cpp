class Solution {
public:
int f(int idx,vector<int> &arr,int d,vector<int> &dp){
    if(idx>=arr.size()) return 0;
    int ans=1;
    if(dp[idx]!=-1) return dp[idx];
    int a=max(0,idx-d);
    int ans1=0;
    for(int i=idx-1;i>=a;i--){
        if(arr[i]<arr[idx]) ans=max(ans,1+f(i,arr,d,dp));
        else break;
    }
    
    for(int i=idx+1;i<arr.size() && i<=(idx+d);i++){
        if(arr[i]<arr[idx]) ans1=max(ans1,1+f(i,arr,d,dp));
        else break;
    }
    
    return dp[idx]=max(ans,ans1);
}
    int maxJumps(vector<int>& arr, int d) {
        int ans=0;
       vector<int> dp(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            ans=max(ans,f(i,arr,d,dp));
        }
        return ans;
        
    }
};