class Solution {
public:
    const int mod = 1e9+7;
    int numberOfWays(string cor) {
        long long ans = 1;
        int cnt = 0;
        for(auto& it : cor){
            if(it=='S') cnt++;
        }
        if(cnt&1 || (cnt==0)) return 0;
        int cc = 0;
        int i = 0;
        while(i<cor.length()){
            if(cor[i]=='S') cc++;
            if(cc==2){
                int j = i + 1;
                while(j<cor.length() && cor[j]!='S') j++;
                if(j==cor.length()) return ans;
                ans = (ans*1ll*(j-i))%mod;
                i = j;
                cc= 1;
            }
            i++;
        }
        return ans%mod;
    }
};