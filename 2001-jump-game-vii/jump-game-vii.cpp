class Solution {
public:
    long long n;
    // int dp[100001];
    // int solve(int i,string& s,int mnj,int mxj){
    //     if(i==n-1) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     bool flag = false;
    //     for(int k = i+mnj;k<=min(n-1,i+mxj);k++){
    //         if(s[k]=='0') flag |= solve(k,s,mnj,mxj);
    //     }
    //     return dp[i] = flag;
    // }
    bool canReach(string s, int minJump, int maxJump) {
        n = s.length();
       // memset(dp,-1,sizeof(dp));
        if(s[n-1]=='1') return false;
        // return solve(0,s,minJump,maxJump);

        queue<long long> q;
        long long mr = 0;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node==n-1) return true;
            for(long long i = max((long long)node+minJump,mr);i<=min((long long)node+maxJump,n-1);i++){
                    if(s[i]=='0') q.push(i);
            }
            mr = min((long long)node+maxJump+1,n-1);
            
        }
        return false;
    }
};