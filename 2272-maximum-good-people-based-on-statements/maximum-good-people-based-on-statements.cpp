class Solution {
public:
    int n;
    bool isValid(vector<int>& ig,vector<vector<int>>& statements){
        for(int i = 0;i<n;i++){
            if(ig[i]==1){
                for(int j = 0;j<n;j++){
                    if(statements[i][j]!=2 && statements[i][j]!=ig[j]) return false;
                }
            }
        }
        return true;
    }
    int solve(int i,vector<int>& ig,vector<vector<int>>& statements){
        if(i==n){
            if(isValid(ig,statements)) return accumulate(ig.begin(),ig.end(),0);
            return 0;
        }
        int ans = 0;
        int ans1 = 0;
        ig[i] = 1;
        ans = solve(i+1,ig,statements);
        ig[i] = 0;
        ans1 = solve(i+1,ig,statements);
        return max(ans,ans1);
    }
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        vector<int> ig(n,0);
        int ans = solve(0,ig,statements);
        return ans;
    }
};