class Solution {
public:
vector<int> left,right;
int n;
int dp[1001];
int f(int i,vector<int> &arr,int d){
    if(dp[i]!=-1) return dp[i];
    int ans=1;
    for(int j = left[i];j<=right[i];j++){
        if(j==i) continue;
        ans = max({ans,1+f(j,arr,d)});
    } 
    return dp[i] = ans;
}
    int maxJumps(vector<int>& arr, int d) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        n = arr.size();
        left.resize(n),right.resize(n);
        for(int i = 0;i<n;i++) left[i] = i,right[i] = i;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(arr[j]>=arr[i]) break;
                right[i] = min({n-1,j,i+d});
            }
            for(int j = i-1;j>=0;j--){
                if(arr[j]>=arr[i]) break;
                left[i] = max({0,j,i-d});
            }
        }
        for(int i=0;i<arr.size();i++){
            ans=max(ans,f(i,arr,d));
        }
        return ans;
        
    }
};