class Solution {
public:
    int n;
    int dp[16][1<<15][16];
    int solve(vector<int>& tasks,int cstr,int mask,int st,int cnt){
        if(cnt==n){
            return 0;
        }
        if(dp[cstr][mask][cnt]!=-1) return dp[cstr][mask][cnt];
        int ans = 123456789;
        for(int i = 0;i<n;i++){
            if((mask&(1<<i))==0){
                if(cstr>=tasks[i]) ans = min(ans,solve(tasks,cstr-tasks[i],mask|(1<<i),st,cnt+1));
                else ans = min(ans,1+solve(tasks,st-tasks[i],mask|(1<<i),st,cnt+1));
            }
        }
        return dp[cstr][mask][cnt] = ans;
    }
    int minSessions(vector<int>& tasks, int st) {
        n = tasks.size();
        int mask = (1<<n);
      //  dp.resize(st+1,vector<vector<int>>(mask+1,vector<int>(n+1,-1)));
      memset(dp,-1,sizeof(dp));
        return 1+solve(tasks,st,mask,st,0);
    }
};