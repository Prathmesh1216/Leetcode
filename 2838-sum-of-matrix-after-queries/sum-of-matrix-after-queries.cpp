class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        int rc= n;
        int cc = n;
        vector<bool> rvis(n),cvis(n);
        for(int i = queries.size()-1;i>=0;i--){
            int t = queries[i][0],id = queries[i][1],val = queries[i][2];
            if(t==0){
                if(rvis[id]) continue;
                ans += (val*1LL*cc);
                rc--;
                rvis[id] = 1;
            }
            else{
                if(cvis[id]) continue;
                cvis[id] = 1;
                ans += (val*1LL*rc);
                cc--;
            }
        }
        return ans;
    }
};