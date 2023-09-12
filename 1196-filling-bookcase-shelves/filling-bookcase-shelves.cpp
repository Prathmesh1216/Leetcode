class Solution {
public:
    int n;
    int dp[1001];
    int solve(int i,int sw,vector<vector<int>>& books){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int height = 0;
        int j = i;
        int ans = 123456789;
        int cw = 0;
        while(j<n && cw+books[j][0]<=sw){
            height = max(height,books[j][1]);
            ans = min(ans,height+solve(j+1,sw,books));
            cw += books[j][0];
            j++;
        }
        return dp[i] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,shelfWidth,books);
    }
};