class Solution {
public:
    int mnsum,mxsum;
    int M = 1e9+7;
    long long dp[24][2][401];
    bool isValid(int sum){
        if(sum<mnsum || sum>mxsum) return false;
        return true;
    }
    long long solve(int i,bool tight,int sum,string& s){
        if(sum>mxsum) return 0;
        if(i==s.length()){
            if(isValid(sum)) return 1;
            return 0;
        }
        if(dp[i][tight][sum]!=-1) return dp[i][tight][sum];
        long long ret = 0;
        int k = (tight) ? s[i]-'0' : 9;
        for (int j=0;j<=k;j++)
        {
            int newTight = 0;
            if(tight && s[i]-'0'==j) newTight = 1;
            ret += solve(i+1,newTight,sum+j,s)%M;
        }
        return dp[i][tight][sum] = ret;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        mnsum = min_sum;
        mxsum = max_sum;
        memset(dp,-1,sizeof(dp));
        long long ans1 = solve(0,1,0,num2);
        memset(dp,-1,sizeof(dp));
        long long ans2 = solve(0,1,0,num1);
        int firstSum = 0;
        for(char &c: num1) firstSum+=(c-'0');
        if(firstSum>=min_sum && firstSum<=max_sum) return (ans1-ans2+1)%M;
        return (ans1-ans2)%M;
    }
};